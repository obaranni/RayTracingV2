/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:11:33 by obaranni          #+#    #+#             */
/*   Updated: 2018/02/27 13:57:32 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void		ft_cam_move_forv(t_scene *scene)
{
	scene->cam.position =
		ft_vec_sum(scene->cam.position,
		vect_multipl_const(scene->cam.w, 15));
}

void		ft_cam_move_back(t_scene *scene)
{
	scene->cam.position =
		vect_substr(scene->cam.position,
		vect_multipl_const(scene->cam.w, 15));
}

void		ft_cam_yaw(t_scene *scene, double angel)
{
	t_mtrx	mt;

	mt = ft_cam_move_arbit_axis(&scene->cam.v,
			angel);
	ft_matrix_vec_mult(mt, &scene->cam.u);
	ft_matrix_vec_mult(mt, &scene->cam.w);
}

void		ft_cam_pitch(t_scene *scene, double angel)
{
	t_mtrx	mt;

	mt = ft_cam_move_arbit_axis(&scene->cam.u,
			angel);
	ft_matrix_vec_mult(mt, &scene->cam.v);
	ft_matrix_vec_mult(mt, &scene->cam.w);
}

void		ft_cam_roll(t_scene *scene, double angel)
{
	t_mtrx	mt;

	mt = ft_cam_move_arbit_axis(&scene->cam.w,
			angel);
	ft_matrix_vec_mult(mt, &scene->cam.u);
	ft_matrix_vec_mult(mt, &scene->cam.v);
}
