/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:31:13 by obaranni          #+#    #+#             */
/*   Updated: 2018/02/27 15:33:43 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			init_camera(t_camera *cam,
		ini_t *ini)
{
	cam->left = (W_W / 2) - W_W;
	cam->right = W_W / 2;
	cam->top = W_H / 2;
	cam->bottom = (W_H / 2) - W_H;
	cam->position = ini_get_pos(ini, 0);
	cam->distanse = ft_atoi(ini_get_prop(ini, 0, "dist"));
	cam->w.x = 0;
	cam->w.y = 0;
	cam->w.z = 1;
	cam->v.x = 0;
	cam->v.y = -1;
	cam->v.z = 0;
	cam->u.x = 1;
	cam->u.y = 0;
	cam->u.z = 0;
}

t_vect			init_cam_ray(double x, double y, const t_camera *cam)
{
	t_vect		dir;
	double		u;
	double		v;
	double		w;

	u = cam->left + (cam->right - cam->left) * x / W_W;
	v = cam->bottom + (cam->top - cam->bottom) * y / W_H;
	w = 1000;
	dir = ft_vec_sum(ft_vec_sum(ft_vec_mul_scal(cam->w, w),
		ft_vec_mul_scal(cam->u, u)), ft_vec_mul_scal(cam->v, v));
	vect_normalise(&dir);
	return (dir);
}
