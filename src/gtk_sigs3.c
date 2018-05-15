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

void	sepia_toggled(GtkToggleButton *button,
						gpointer user_data)
{
	t_env	*env;

	env = (t_env *)user_data;
	env->scene->sepia_flag = gtk_toggle_button_get_active(button);
	if (env->mute_signals == 0)
		draw(env);
}

void	value_pos_z(GtkAdjustment *adjustment,
							gpointer user_data)
{
	t_env	*env;

	(void)adjustment;
	env = (t_env *)user_data;
	if (env->current)
	{
		env->current->position.z = gtk_adjustment_get_value(env->gtk.posz_adj);
		if (env->mute_signals == 0)
			draw(env);
	}
}

void	value_pos_y(GtkAdjustment *adjustment,
							gpointer user_data)
{
	t_env	*env;

	(void)adjustment;
	env = (t_env *)user_data;
	if (env->current)
	{
		env->current->position.y = gtk_adjustment_get_value(env->gtk.posy_adj);
		if (env->mute_signals == 0)
			draw(env);
	}
}

void	value_pos_x(GtkAdjustment *adjustment,
							gpointer user_data)
{
	t_env	*env;

	(void)adjustment;
	env = (t_env *)user_data;
	if (env->current)
	{
		env->current->position.x = gtk_adjustment_get_value(env->gtk.posx_adj);
		if (env->mute_signals == 0)
			draw(env);
	}
}

void	blue_value_adj(GtkAdjustment *adjustment,
			gpointer user_data)
{
	t_env	*env;

	(void)adjustment;
	env = (t_env *)user_data;
	if (env->current && env->mute_signals < 2)
	{
		env->current->color.b =
			(guchar)gtk_adjustment_get_value(env->gtk.blue_adj);
		if (env->mute_signals == 0)
			draw(env);
	}
	else
		gtk_adj_set_val(env);
}
