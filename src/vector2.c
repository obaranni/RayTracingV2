/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 03:15:43 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/02/27 15:02:05 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_vect			vector_cross(t_vect v1, t_vect v2)
{
	t_vect		res;

	res.x = v1.y * v2.z + v2.y * v1.z;
	res.y = v1.x * v2.z + v2.x * v1.z;
	res.z = v1.x * v2.y + v2.x * v1.y;
	return (res);
}

t_vect			vect_sum(t_vect end, t_vect start)
{
	t_vect		res;

	res.x = end.x + start.x;
	res.y = end.y + start.y;
	res.z = end.z + start.z;
	return (res);
}

t_cut			new_cut(int type, int axis, double ax_min, double ax_max)
{
	t_cut		cut;

	cut.type = type;
	cut.axis = axis;
	cut.cut_min = ax_min;
	cut.cut_max = ax_max;
	return (cut);
}

t_vecparr		new_vecparr(t_vect *a_b_c, const t_vect *start_pnt,
							const t_vect *vect)
{
	t_vecparr	v;

	v.a_b_c = a_b_c;
	v.start_pnt = start_pnt;
	v.vect = vect;
	return (v);
}

t_vecparr2		new_vecparr2(t_vect *inters_pnt, t_vect *dirr)
{
	t_vecparr2	v;

	v.inters_pnt = inters_pnt;
	v.dirr = dirr;
	return (v);
}
