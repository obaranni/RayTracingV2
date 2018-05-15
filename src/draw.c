/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:13:41 by obaranni          #+#    #+#             */
/*   Updated: 2018/02/27 13:59:20 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			*render_main_image(void *data)
{
	t_env		*env;
	t_scene		*scene;

	env = (t_env *)data;
	scene = env->scene;
	render(scene, scene->qual, &scene->img);
	scene->img.image = env->gtk.main_gtk_img;
	gtk_image_set_from_pixbuf(env->gtk.main_gtk_img, scene->img.pixbuf);
	scale_img(&(scene->img), 1.0 / 3, &(scene->pre_img), 0);
	gtk_image_set_from_pixbuf(scene->pre_img.image, scene->pre_img.pixbuf);
	gtk_spinner_stop(env->gtk.spinner);
	env->mute_signals = 0;
	return (NULL);
}

void			draw(t_env *env)
{
	env->mute_signals = 2;
	gtk_spinner_start(env->gtk.spinner);
	while (gtk_events_pending())
		gtk_main_iteration();
	render_main_image(env);
}
