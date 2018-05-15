/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 23:43:45 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/10/24 23:43:47 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					intersect_elips(t_obj *obj,
									const t_vect *start_pnt,
									const t_vect *vect,
									t_vect *inters_pnt)
{
	t_elips			*elips;
	double			t;
	t_vect			dist;
	t_vect			a_b_c;
	t_vect			abc;

	elips = (t_elips *)obj->data;
	dist = vect_substr(*start_pnt, elips->position);
	abc.x = 2 * elips->dist * vect_multipl(*vect, elips->dir);
	abc.y = pow(elips->rad, 2) + (2 * elips->dist *
		vect_multipl(dist, elips->dir)) - elips->dist;
	a_b_c.x = 4 * pow(elips->rad, 2) * vect_multipl(*vect, *vect) -
														pow(abc.x, 2);
	a_b_c.y = 2 * (4 * pow(elips->rad, 2) * vect_multipl(*vect, dist) -
														abc.x * abc.y);
	a_b_c.z = 4 * pow(elips->rad, 2) * vect_multipl(dist, dist) - pow(abc.y, 2);
	elips->a_b_c = a_b_c;
	if (!check_d(&t, new_vecparr(&a_b_c, start_pnt, vect), obj))
		return (0);
	dist = vect_multipl_const(*vect, t);
	inters_pnt->x = start_pnt->x + dist.x;
	inters_pnt->y = start_pnt->y + dist.y;
	inters_pnt->z = start_pnt->z + dist.z;
	return (1);
}

t_col				get_col_elips(const void *data,
							const t_vect *inters_pnt)
{
	const t_elips	*elips;

	(void)inters_pnt;
	elips = (t_elips *)data;
	return (elips->color);
}

void				destruct_elips(void *data)
{
	t_elips			*elips;

	elips = (t_elips *)data;
	free(elips);
}

/*
**	check = 1 - pow(elips->a_b_c.y, 2)/pow(elips->a_b_c.x, 2);
**	checkv = vect_multipl_const(elips->dir, check);
**	checkvec = vect_multipl(norm, elips->dir);
**	norm = vect_substr(norm, vect_multipl_const(checkv, checkvec));
*/

t_vect				get_norm_vect_elips(void *data,
						const t_vect *inters_pnt)
{
	t_elips			*elips;
	t_vect			vect;
	t_vect			norm;

	elips = (t_elips *)data;
	vect = vect_sum(elips->position, vect_multipl_const(elips->dir,
												elips->dist * 0.5));
	norm = vect_substr(*inters_pnt, vect);
	vect_normalise(&norm);
	return (norm);
}

t_obj				*new_elips(t_param param, double rad,
					double dist, t_cut cut)
{
	t_obj			*obj;
	t_elips			*elips;

	elips = ft_memalloc(sizeof(*elips));
	elips->position = param.pos;
	elips->dir = param.dir;
	elips->color = param.col;
	elips->rad = rad;
	elips->dist = dist;
	elips->cut.type = cut.type;
	elips->cut.axis = cut.axis;
	elips->cut.cut_min = cut.cut_min;
	elips->cut.cut_max = cut.cut_max;
	vect_normalise(&elips->dir);
	obj = ft_memalloc(sizeof(*obj));
	obj->data = (void *)elips;
	((t_elips*)obj->data)->obj = obj;
	obj->type = 6;
	obj->intersect = intersect_elips;
	obj->cut = cut_elips;
	obj->get_col = get_col_elips;
	obj->destruct_data = destruct_elips;
	obj->get_norm_vect = get_norm_vect_elips;
	return (obj);
}
