/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disctri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:24:34 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/10/30 03:24:47 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					intersect_disc(t_obj *obj,
									const t_vect *start_pnt,
									const t_vect *vect,
									t_vect *inters_pnt)
{
	const t_disc	*disc;
	double			d;
	double			t;
	t_vect			dist;
	t_vect			check;

	disc = (t_disc *)obj->data;
	d = vect_multipl(*vect, disc->direction);
	if (d == 0.0)
		return (0);
	dist = vect_substr(disc->position, *start_pnt);
	t = vect_multipl(dist, disc->direction) / d;
	if (t < 0.000001 || t > 1.0e30)
		return (0);
	dist = vect_multipl_const(*vect, t);
	inters_pnt->x = start_pnt->x + dist.x;
	inters_pnt->y = start_pnt->y + dist.y;
	inters_pnt->z = start_pnt->z + dist.z;
	check = (vect_substr(*inters_pnt, disc->position));
	if (!(vect_multipl(check, check) < pow(disc->radius, 2)))
		return (0);
	return (1);
}

t_col				get_col_disc(const void *data,
							const t_vect *inters_pnt)
{
	const t_disc	*disc;

	(void)inters_pnt;
	disc = (t_disc *)data;
	return (disc->color);
}

void				destruct_disc(void *data)
{
	t_disc		*disc;

	disc = (t_disc *)data;
	free(disc);
}

t_vect				get_norm_vect_disc(void *data,
										const t_vect *inters_pnt)
{
	t_disc			*disc;
	t_vect			res;

	(void)inters_pnt;
	disc = (t_disc *)data;
	res.x = disc->direction.x;
	res.y = disc->direction.y;
	res.z = disc->direction.z;
	vect_normalise(&res);
	return (res);
}

t_obj				*new_disc(t_vect pos, t_vect dir, t_col col, double rad)
{
	t_obj			*obj;
	t_disc			*disc;

	disc = ft_memalloc(sizeof(*disc));
	disc->position = pos;
	disc->color = col;
	disc->direction = dir;
	disc->radius = rad;
	vect_normalise(&disc->direction);
	obj = ft_memalloc(sizeof(*obj));
	obj->data = (void *)disc;
	((t_disc*)obj->data)->obj = obj;
	obj->type = 5;
	obj->intersect = intersect_disc;
	obj->get_col = get_col_disc;
	obj->destruct_data = destruct_disc;
	obj->get_norm_vect = get_norm_vect_disc;
	return (obj);
}
