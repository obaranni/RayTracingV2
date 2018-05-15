/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_sigs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:25:33 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/03/05 17:45:26 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			spec_changed(GtkAdjustment *adjustment,
				gpointer user_data)
{
	t_env		*env;

	(void)adjustment;
	env = (t_env *)user_data;
	if (env->current && env->mute_signals < 2)
	{
		env->scene->specularity =
				(gint32)gtk_adjustment_get_value(env->gtk.spec_adj);
		if (env->mute_signals == 0)
			draw(env);
	}
	else
		gtk_adj_set_val(env);
}

void			refr_changed(GtkAdjustment *adjustment,
				gpointer user_data)
{
	t_env		*env;

	(void)adjustment;
	env = (t_env *)user_data;
	if (env->current && env->mute_signals < 2)
	{
		env->current->obj->refr = gtk_adjustment_get_value(env->gtk.refr_adj);
		if (env->mute_signals == 0)
			draw(env);
	}
	else
		gtk_adj_set_val(env);
}

void			refl_changed(GtkAdjustment *adjustment,
				gpointer user_data)
{
	t_env		*env;

	(void)adjustment;
	env = (t_env *)user_data;
	if (env->current && env->mute_signals < 2)
	{
		env->current->obj->refl = gtk_adjustment_get_value(env->gtk.refl_adj);
		if (env->mute_signals == 0)
			draw(env);
	}
	else
		gtk_adj_set_val(env);
}

void			cartoon_toggled(GtkToggleButton *button,
					gpointer user_data)
{
	t_env		*env;

	env = (t_env *)user_data;
	env->scene->cartoon_flag = gtk_toggle_button_get_active(button);
	if (env->mute_signals == 0)
		draw(env);
}

void			null_but_clicked(GtkButton *button,
						gpointer user_data)
{
	t_env		*env;

	(void)button;
	env = (t_env *)user_data;
	if (env->current != NULL)
	{
		gtk_widget_hide(env->gtk.obj_box);
		env->current = NULL;
		gtk_label_set_text(GTK_LABEL(env->gtk.label_null),
							"Control returned to camera");
		gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "None");
	}
}
