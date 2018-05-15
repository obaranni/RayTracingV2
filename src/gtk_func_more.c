/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_func_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:25:33 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/03/05 17:45:26 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void	set_gtk_obj_name(t_env *env)
{
	if (env->current)
	{
		gtk_label_set_text(GTK_LABEL(env->gtk.label_null), "Object in control");
		if (env->current->obj->type == 0)
			gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "Plane");
		else if (env->current->obj->type == 1)
			gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "Sphere");
		else if (env->current->obj->type == 2)
			gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "Cylinder");
		else if (env->current->obj->type == 3)
			gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "Cone");
		else if (env->current->obj->type == 4)
			gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name),
								"Polygone (Strictly confidential)");
		else if (env->current->obj->type == 5)
			gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "Disc");
		else if (env->current->obj->type == 6)
			gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "Elips");
		else if (env->current->obj->type == 7)
			gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "Parabaloid");
		else if (env->current->obj->type == 8)
			gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "Square");
	}
	else
		gtk_label_set_text(GTK_LABEL(env->gtk.lab_obj_name), "None");
}
