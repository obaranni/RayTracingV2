/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:59:09 by obaranni          #+#    #+#             */
/*   Updated: 2018/02/27 14:01:24 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_mtrx		ft_cam_move_arbit_axis(t_vect *v, double ang_gam)
{
	t_mtrx	r;
	double	c;

	c = (1 - cos(ang_gam));
	r.mtrx[0][0] = cos(ang_gam) + v->x * v->x * c;
	r.mtrx[1][0] = v->z * sin(ang_gam) + v->y * v->x * c;
	r.mtrx[2][0] = -v->y * sin(ang_gam) + v->z * v->x * c;
	r.mtrx[0][1] = -v->z * sin(ang_gam) + v->x * v->y * c;
	r.mtrx[1][1] = cos(ang_gam) + v->y * v->y * c;
	r.mtrx[2][1] = v->x * sin(ang_gam) + v->z * v->y * c;
	r.mtrx[0][2] = v->y * sin(ang_gam) + v->x * v->z * c;
	r.mtrx[1][2] = -v->x * sin(ang_gam) + v->y * v->z * c;
	r.mtrx[2][2] = cos(ang_gam) + v->z * v->z * c;
	ft_matrix_vec_mult(r, v);
	return (r);
}

void		ft_matrix_vec_mult(t_mtrx mt, t_vect *v1)
{
	t_vect	tmp;

	tmp.x = v1->x * mt.mtrx[0][0] + v1->y * mt.mtrx[0][1]
		+ v1->z * mt.mtrx[0][2] + 1 * mt.mtrx[0][3];
	tmp.y = v1->x * mt.mtrx[1][0] + v1->y * mt.mtrx[1][1]
		+ v1->z * mt.mtrx[1][2] + 1 * mt.mtrx[1][3];
	tmp.z = v1->x * mt.mtrx[2][0] + v1->y * mt.mtrx[2][1]
		+ v1->z * mt.mtrx[2][2] + 1 * mt.mtrx[2][3];
	*v1 = tmp;
}
