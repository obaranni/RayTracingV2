/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:25:33 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/03/05 17:45:26 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void	gtk_adj_set_val(t_env *env)
{
	if (env->current)
	{
		gtk_adjustment_set_value(env->gtk.red_adj, env->current->color.r);
		gtk_adjustment_set_value(env->gtk.green_adj, env->current->color.g);
		gtk_adjustment_set_value(env->gtk.blue_adj, env->current->color.b);
		gtk_adjustment_set_value(env->gtk.refr_adj, env->current->obj->refr);
		gtk_adjustment_set_value(env->gtk.refl_adj, env->current->obj->refl);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(env->gtk.xspin),
			env->current->position.x);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(env->gtk.yspin),
			env->current->position.y);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(env->gtk.zspin),
			env->current->position.z);
	}
	set_gtk_obj_name(env);
	gtk_adjustment_set_value(env->gtk.spec_adj, env->scene->specularity);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(env->gtk.sepia_check),
			env->scene->sepia_flag);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(env->gtk.cartoon_check),
			env->scene->cartoon_flag);
	env->mute_signals = 0;
}

void	gtk_set_value_pos(t_env *env)
{
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(env->gtk.spscale),
		env->current->position.x);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(env->gtk.refrscale),
		env->current->position.y);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(env->gtk.reflscale),
		env->current->position.z);
}

void	get_gtk_pointers_adj(t_env *env)
{
	env->gtk.red_adj = gtk_range_get_adjustment(GTK_RANGE(env->gtk.rscale));
	env->gtk.green_adj = gtk_range_get_adjustment(GTK_RANGE(env->gtk.gscale));
	env->gtk.blue_adj = gtk_range_get_adjustment(GTK_RANGE(env->gtk.bscale));
	env->gtk.spec_adj = gtk_range_get_adjustment(GTK_RANGE(env->gtk.spscale));
	env->gtk.refr_adj = gtk_range_get_adjustment(GTK_RANGE(env->gtk.refrscale));
	env->gtk.refl_adj = gtk_range_get_adjustment(GTK_RANGE(env->gtk.reflscale));
	env->gtk.posx_adj =
		gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(env->gtk.xspin));
	env->gtk.posy_adj =
		gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(env->gtk.yspin));
	env->gtk.posz_adj =
		gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(env->gtk.zspin));
}

void	get_gtk_pointers2(t_env *env, GtkBuilder *builder)
{
	env->gtk.lab_obj_name =
			GTK_WIDGET(gtk_builder_get_object(builder, "lab_obj_name"));
	env->gtk.back_butt =
			GTK_WIDGET(gtk_builder_get_object(builder, "backup_button"));
	env->gtk.save_butt =
			GTK_WIDGET(gtk_builder_get_object(builder, "screenshot_butt"));
}

void	get_gtk_pointers(t_env *env, GtkBuilder *builder)
{
	env->gtk.gscale =
		GTK_WIDGET(gtk_builder_get_object(builder, "scale_green"));
	env->gtk.rscale = GTK_WIDGET(gtk_builder_get_object(builder, "scale_red"));
	env->gtk.bscale = GTK_WIDGET(gtk_builder_get_object(builder, "scale_blue"));
	env->gtk.spscale = GTK_WIDGET(gtk_builder_get_object(builder, "spscale"));
	env->gtk.refrscale =
		GTK_WIDGET(gtk_builder_get_object(builder, "refrscale"));
	env->gtk.reflscale =
		GTK_WIDGET(gtk_builder_get_object(builder, "reflscale"));
	env->gtk.xspin = GTK_WIDGET(gtk_builder_get_object(builder, "xspin"));
	env->gtk.yspin = GTK_WIDGET(gtk_builder_get_object(builder, "yspin"));
	env->gtk.zspin = GTK_WIDGET(gtk_builder_get_object(builder, "zspin"));
	env->gtk.sepia_check =
		GTK_WIDGET(gtk_builder_get_object(builder, "sepia"));
	env->gtk.cartoon_check =
			GTK_WIDGET(gtk_builder_get_object(builder, "cartoon"));
	env->gtk.label_null =
		GTK_WIDGET(gtk_builder_get_object(builder, "label_null"));
	env->gtk.null_butt =
		GTK_WIDGET(gtk_builder_get_object(builder, "null_butt"));
	env->gtk.obj_box = GTK_WIDGET(gtk_builder_get_object(builder, "obj_box"));
	env->gtk.spinner =
		GTK_SPINNER(GTK_WIDGET(gtk_builder_get_object(builder, "spinner")));
	get_gtk_pointers_adj(env);
	get_gtk_pointers2(env, builder);
}
