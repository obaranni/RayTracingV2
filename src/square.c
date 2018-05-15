/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:24:55 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/10/30 03:24:58 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					intersect_square(t_obj *obj,
									const t_vect *start_pnt,
									const t_vect *vect,
									t_vect *inters_pnt)
{
	t_square		*square;
	double			d;
	double			t;
	t_vect			dist;

	square = (t_square *)obj->data;
	check_refr_pos(square, obj);
	change_side_pos(square, obj);
	d = vect_multipl(*vect, square->direction);
	if (d == 0.0)
		return (0);
	dist = vect_substr(square->position, *start_pnt);
	t = vect_multipl(dist, square->direction) / d;
	t = check_square_cut(t, start_pnt, vect, obj->data);
	if (t < 0.000001 || t > 1.0e30)
		return (0);
	dist = vect_multipl_const(*vect, t);
	inters_pnt->x = start_pnt->x + dist.x;
	inters_pnt->y = start_pnt->y + dist.y;
	inters_pnt->z = start_pnt->z + dist.z;
	return (1);
}

t_col				get_col_square(const void *data,
							const t_vect *inters_pnt)
{
	const t_square	*square;

	(void)inters_pnt;
	square = (t_square *)data;
	return (square->color);
}

void				destruct_square(void *data)
{
	t_square		*square;

	square = (t_square *)data;
	free(square);
}

t_vect				get_norm_vect_square(void *data,
										const t_vect *inters_pnt)
{
	t_square		*square;
	t_vect			res;

	(void)inters_pnt;
	square = (t_square *)data;
	res.x = square->direction.x;
	res.y = square->direction.y;
	res.z = square->direction.z;
	vect_normalise(&res);
	return (res);
}

t_obj				*new_square(t_param param, double k,
					int side, t_scene *scene)
{
	t_obj			*obj;
	t_square		*square;

	(void)scene;
	square = ft_memalloc(sizeof(*square));
	square->position = param.pos;
	square->color = param.col;
	square->direction = param.dir;
	square->k = k;
	square->side = side;
	vect_normalise(&square->direction);
	obj = ft_memalloc(sizeof(*obj));
	obj->data = (void *)square;
	((t_square*)obj->data)->obj = obj;
	obj->type = 8;
	obj->intersect = intersect_square;
	obj->get_col = get_col_square;
	obj->destruct_data = destruct_square;
	obj->get_norm_vect = get_norm_vect_square;
	return (obj);
}
