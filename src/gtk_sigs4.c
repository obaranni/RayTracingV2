/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_sigs3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:25:33 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/03/05 17:45:26 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void		green_value_adj(GtkAdjustment *adjustment,
							gpointer user_data)
{
	t_env	*env;

	(void)adjustment;
	env = (t_env *)user_data;
	if (env->current && env->mute_signals < 2)
	{
		env->current->color.g =
				(guchar)gtk_adjustment_get_value(env->gtk.green_adj);
		if (env->mute_signals == 0)
			draw(env);
	}
	else
		gtk_adj_set_val(env);
}

void		red_value_adj(GtkAdjustment *adjustment,
							gpointer user_data)
{
	t_env	*env;

	(void)adjustment;
	env = (t_env *)user_data;
	if (env->current && env->mute_signals < 2)
	{
		env->current->color.r =
				(guchar)gtk_adjustment_get_value(env->gtk.red_adj);
		if (env->mute_signals == 0)
			draw(env);
	}
	else
		gtk_adj_set_val(env);
}

void		backup_clicked(GtkButton *button,
						gpointer user_data)
{
	t_env	*env;

	(void)button;
	env = (t_env *)user_data;
	backup(env);
	gtk_button_set_label(button, "Scene has been saved");
	env->gtk.backup_fl = 0;
}

void		screenshot_clicked(GtkButton *button,
						gpointer user_data)
{
	t_env		*env;
	char		cur_name[7];
	char		*n;

	env = (t_env *)user_data;
	cur_name[6] = '\0';
	(void)button;
	env->gtk.name[0]++;
	if (env->gtk.name[0] == 123)
	{
		env->gtk.name[0] = 97;
		env->gtk.num++;
	}
	n = ft_itoa(env->gtk.num);
	ft_strcpy(cur_name, env->gtk.name);
	ft_strcat(cur_name, "_pic");
	ft_strcat(cur_name, n);
	gdk_pixbuf_save(env->scene->img.pixbuf, cur_name,
		"jpg", NULL, "quality", "100", NULL);
	gtk_button_set_label(button, "Saved");
	env->gtk.save_fl = 0;
	free(n);
	env->current = ((t_obj *)env->scene->objs->data)->data;
}
