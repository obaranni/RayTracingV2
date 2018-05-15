/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_sigs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:25:33 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/03/05 17:45:26 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			check_selected_obj(t_env *env, const t_quality *m_q)
{
	if (m_q->obj && m_q->obj->type != 4)
	{
		env->current = (t_square *)m_q->obj->data;
		if ((m_q->obj->type == 8) && (((t_square*)m_q->obj->data)->side != 0))
			env->current = (t_square*)m_q->obj->parent->data;
		env->mute_signals = 1;
		gtk_adj_set_val(env);
	}
	else
	{
		env->current = NULL;
		gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "None");
		gtk_widget_hide(env->gtk.obj_box);
	}
}

t_crutch		positive_if_answ(t_env *env, t_scene *scene,
							t_quality *m_q, GdkEventButton *event)
{
	t_crutch	crutch;

	scene = env->scene;
	m_q->x = (int)event->x;
	m_q->y = (int)event->y;
	m_q->dir = init_cam_ray(m_q->x, m_q->y, &scene->cam);
	find_closest_obj(scene, &(m_q->obj), scene->cam.position,
					new_vecparr2(&(m_q->inters_pnt), &(m_q->dir)));
	check_selected_obj(env, m_q);
	crutch_save(&crutch, env, scene, m_q);
	return (crutch);
}

void			negative_if_anw(t_env *env, t_scene *scene)
{
	env->scene = scene;
	env->current = NULL;
	gtk_widget_hide(env->gtk.obj_box);
	if (scene->img.image)
	{
		env->mute_signals = 1;
		gtk_adj_set_val(env);
		gtk_image_set_from_pixbuf(env->gtk.main_gtk_img, scene->img.pixbuf);
	}
	else
	{
		gtk_adj_set_val(env);
		draw(env);
	}
}

gboolean		button_press_callback(GtkWidget *boxscreen,
					GdkEventButton *event, gpointer data)
{
	t_env		*env;
	t_quality	*m_q;
	t_scene		*scene;
	t_crutch	crutch;

	env = (t_env *)data;
	m_q = ft_memalloc(sizeof(*m_q));
	if (!(scene = g_object_get_data(G_OBJECT(boxscreen), "scene")))
	{
		crutch = positive_if_answ(env, scene, m_q, event);
		env = crutch.env;
		scene = crutch.scene;
		m_q = crutch.m_q;
	}
	else
		negative_if_anw(env, scene);
	if (env->current && (m_q->obj->type != 4))
	{
		gtk_adj_set_val(env);
		gtk_widget_show(env->gtk.obj_box);
	}
	else
		gtk_widget_hide(env->gtk.obj_box);
	free(m_q);
	return (TRUE);
}
