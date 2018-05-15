/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:24:55 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/10/30 03:24:58 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					intersect_plane(t_obj *obj,
									const t_vect *start_pnt,
									const t_vect *vect,
									t_vect *inters_pnt)
{
	const t_plane	*plane;
	double			d;
	double			t;
	t_vect			dist;

	plane = (t_plane *)obj->data;
	d = vect_multipl(*vect, plane->direction);
	if (d == 0.0)
		return (0);
	dist = vect_substr(plane->position, *start_pnt);
	t = vect_multipl(dist, plane->direction) / d;
	t = check_plane_cut(t, start_pnt, vect, obj->data);
	obj->current_col = plane->color;
	if (t < 0.000001 || t > 1.0e30)
		return (0);
	dist = vect_multipl_const(*vect, t);
	inters_pnt->x = start_pnt->x + dist.x;
	inters_pnt->y = start_pnt->y + dist.y;
	inters_pnt->z = start_pnt->z + dist.z;
	return (1);
}

t_col				get_col_plane(const void *data,
							const t_vect *inters_pnt)
{
	const t_plane	*plane;

	(void)inters_pnt;
	plane = (t_plane *)data;
	return (plane->color);
}

void				destruct_plane(void *data)
{
	t_plane		*plane;

	plane = (t_plane *)data;
	free(plane);
}

t_vect				get_norm_vect_plane(void *data,
										const t_vect *inters_pnt)
{
	t_plane			*plane;
	t_vect			res;

	(void)inters_pnt;
	plane = (t_plane *)data;
	res.x = plane->direction.x;
	res.y = plane->direction.y;
	res.z = plane->direction.z;
	vect_normalise(&res);
	return (res);
}

t_obj				*new_plane(t_vect pos, t_vect dir, t_col col, t_cut cut)
{
	t_obj			*obj;
	t_plane			*plane;

	plane = ft_memalloc(sizeof(*plane));
	plane->position = pos;
	plane->color = col;
	plane->direction = dir;
	plane->cut.type = cut.type;
	plane->cut.axis = cut.axis;
	plane->cut.cut_min = cut.cut_min;
	plane->cut.cut_max = cut.cut_max;
	vect_normalise(&plane->direction);
	obj = ft_memalloc(sizeof(*obj));
	obj->data = (void *)plane;
	((t_plane*)obj->data)->obj = obj;
	obj->type = 0;
	obj->intersect = intersect_plane;
	obj->get_col = get_col_plane;
	obj->destruct_data = destruct_plane;
	obj->get_norm_vect = get_norm_vect_plane;
	return (obj);
}
