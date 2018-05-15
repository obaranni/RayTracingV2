/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:55:38 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/05/13 20:55:53 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			cam_hooks2(GtkWidget *widget,
							GdkEventKey *event, t_scene *scene)
{
	(void)widget;
	if (event->keyval == GDK_KEY_a)
		ft_cam_yaw(scene, (M_PI / 180) * 5);
	else if (event->keyval == GDK_KEY_d)
		ft_cam_yaw(scene, -(M_PI / 180) * 5);
	else if (event->keyval == GDK_KEY_s)
		ft_cam_pitch(scene, (M_PI / 180) * 5);
	else if (event->keyval == GDK_KEY_w)
		ft_cam_pitch(scene, -(M_PI / 180) * 5);
	else if (event->keyval == GDK_KEY_e)
		ft_cam_roll(scene, (M_PI / 180) * 5);
	else if (event->keyval == GDK_KEY_q)
		ft_cam_roll(scene, -(M_PI / 180) * 5);
	else if (event->keyval == GDK_KEY_KP_Subtract)
		ft_cam_move_back(scene);
	else if (event->keyval == GDK_KEY_KP_Add)
		ft_cam_move_forv(scene);
	else if (event->keyval == GDK_KEY_KP_7)
		scene->cam.position.z += 100;
	else if (event->keyval == GDK_KEY_KP_9)
		scene->cam.position.z -= 100;
}

int				cam_hooks(GtkWidget *widget, GdkEventKey *event, t_scene *scene)
{
	if (!scene->env->current)
	{
		if (event->keyval == GDK_KEY_KP_2)
			scene->cam.position.y -= 100;
		else if (event->keyval == GDK_KEY_KP_8)
			scene->cam.position.y += 100;
		else if (event->keyval == GDK_KEY_KP_6)
			scene->cam.position.x += 100;
		else if (event->keyval == GDK_KEY_KP_4)
			scene->cam.position.x -= 100;
		cam_hooks2(widget, event, scene);
	}
	if ((event->keyval == GDK_KEY_a || event->keyval == GDK_KEY_d
		|| event->keyval == GDK_KEY_s || event->keyval == GDK_KEY_w
		|| event->keyval == GDK_KEY_e || event->keyval == GDK_KEY_q
		|| event->keyval == GDK_KEY_KP_Subtract
		|| event->keyval == GDK_KEY_KP_Add
		|| event->keyval == GDK_KEY_KP_2 || event->keyval == GDK_KEY_KP_8
		|| event->keyval == GDK_KEY_KP_6 || event->keyval == GDK_KEY_KP_4
		|| event->keyval == GDK_KEY_KP_7 || event->keyval == GDK_KEY_KP_9)
		&& !scene->env->current)
		return (1);
	return (0);
}

int				obj_hooks(GtkWidget *widget, GdkEventKey *event, t_env *env)
{
	t_vect		shift;

	(void)widget;
	shift = new_v(0, 0, 0);
	if (env->current)
	{
		shift.x -= event->keyval == GDK_KEY_a ? 50 : 0;
		shift.y -= event->keyval == GDK_KEY_s ? 50 : 0;
		shift.z -= event->keyval == GDK_KEY_q ? 50 : 0;
		shift.x += event->keyval == GDK_KEY_d ? 50 : 0;
		shift.y += event->keyval == GDK_KEY_w ? 50 : 0;
		shift.z += event->keyval == GDK_KEY_e ? 50 : 0;
		if ((shift.x + shift.y + shift.z) != 0)
		{
			env->mute_signals = 1;
			env->current->position =
					vect_sum(env->current->position, shift);
			gtk_adj_set_val(env);
			return (1);
		}
	}
	return (0);
}

static int		ft_key_press(GtkWidget *widget,
				GdkEventKey *event, t_scene *scene)
{
	int			flag;

	flag = 0;
	flag += cam_hooks(widget, event, scene);
	flag += qual_hooks(widget, event, scene);
	flag += rotations(widget, event, scene);
	flag += obj_hooks(widget, event, scene->env);
	if (event->keyval == GDK_KEY_b)
	{
		backup(scene->env);
		flag += 1;
	}
	if (flag)
		draw(scene->env);
	return (0);
}

void			ft_hooks(GtkWidget *widget, GdkEventKey *event,
						gpointer user_data)
{
	t_env *env;

	env = (t_env*)user_data;
	if (env->gtk.backup_fl == 0)
	{
		gtk_button_set_label(GTK_BUTTON(env->gtk.back_butt), "Backup button");
		env->gtk.backup_fl = 1;
	}
	if (env->gtk.save_fl == 0)
	{
		gtk_button_set_label(GTK_BUTTON(env->gtk.save_butt), "Save image");
		env->gtk.save_fl = 1;
	}
	if (event->keyval == GDK_KEY_Escape)
		ft_destroy_env(env);
	if (env->mute_signals == 0)
		ft_key_press(widget, event, env->scene);
}
