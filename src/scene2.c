/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:10:11 by obaranni          #+#    #+#             */
/*   Updated: 2018/03/19 23:13:43 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			image_init(t_img *img, int w, int h)
{
	if (img->pixbuf)
		free(img->pixbuf);
	img->pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, w, h);
	img->img_str = gdk_pixbuf_get_pixels(img->pixbuf);
	img->sl = gdk_pixbuf_get_rowstride(img->pixbuf);
	img->bpp = gdk_pixbuf_get_n_channels(img->pixbuf);
	img->w = w;
	img->h = h;
}

void			scene_del(t_scene *scene)
{
	free(scene->name);
	free(scene);
}

void			add_obj_to_scene(t_scene *scene, t_obj *obj)
{
	obj->scene = scene;
	scene->objs = add_bid_lst(scene->objs, obj);
}
