/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:39:01 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/03/19 22:40:13 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					intersect_parab(t_obj *obj,
										const t_vect *start_pnt,
										const t_vect *vect,
										t_vect *inters_pnt)
{
	t_parab			*parab;
	double			t;
	t_vect			dist;
	t_vect			a_b_c;

	parab = (t_parab *)obj->data;
	dist = vect_substr(*start_pnt, parab->position);
	a_b_c.x = vect_multipl(*vect, *vect)
				- pow(vect_multipl(*vect, parab->direction), 2);
	a_b_c.y = 2.0 * (vect_multipl(*vect, dist)
					- (vect_multipl(*vect, parab->direction)
					* (vect_multipl(dist, parab->direction) + (2 * parab->k))));
	a_b_c.z = vect_multipl(dist, dist)
				- (vect_multipl(dist, parab->direction) *
					(vect_multipl(dist, parab->direction) + (4 * parab->k)));
	if (!check_d(&t, new_vecparr(&a_b_c, start_pnt, vect), obj))
		return (0);
	dist = vect_multipl_const(*vect, t);
	inters_pnt->x = start_pnt->x + dist.x;
	inters_pnt->y = start_pnt->y + dist.y;
	inters_pnt->z = start_pnt->z + dist.z;
	return (1);
}

t_col				get_col_parab(const void *data,
										const t_vect *inters_pnt)
{
	t_parab			*parab;

	(void)inters_pnt;
	parab = (t_parab *)data;
	return (parab->color);
}

void				destruct_parab(void *data)
{
	t_parab		*parab;

	parab = (t_parab *)data;
	free(parab);
}

t_vect				get_norm_vect_parab(void *data,
											const t_vect *inters_pnt)
{
	t_parab			*parab;
	t_vect			vect_proj;
	t_vect			res;
	double			m;

	res = *inters_pnt;
	parab = (t_parab *)data;
	res = vect_substr(res, parab->position);
	m = vect_multipl(res, parab->direction);
	m = m + parab->k;
	vect_proj = vect_multipl_const(parab->direction, m);
	res = vect_substr(res, vect_proj);
	vect_normalise(&res);
	return (res);
}

t_obj				*new_parab(t_param param, double scalar, t_cut cut)
{
	t_obj			*obj;
	t_parab			*parab;

	parab = ft_memalloc(sizeof(*parab));
	parab->position = param.pos;
	parab->k = scalar;
	parab->color = param.col;
	parab->direction = param.dir;
	parab->cut.type = cut.type;
	parab->cut.axis = cut.axis;
	parab->cut.cut_min = cut.cut_min;
	parab->cut.cut_max = cut.cut_max;
	vect_normalise(&parab->direction);
	obj = ft_memalloc(sizeof(*obj));
	obj->type = 7;
	obj->data = (void *)parab;
	((t_parab*)obj->data)->obj = obj;
	obj->intersect = intersect_parab;
	obj->cut = cut_parab;
	obj->get_col = get_col_parab;
	obj->destruct_data = destruct_parab;
	obj->get_norm_vect = get_norm_vect_parab;
	return (obj);
}
