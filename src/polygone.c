/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:24:55 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/03/19 22:38:22 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					intersect_poly(t_obj *obj,
									const t_vect *start_pnt,
									const t_vect *vect,
									t_vect *inters_pnt)
{
	t_poly			*poly;
	double			d;
	double			t;
	t_vect			dist;

	poly = (t_poly *)obj->data;
	d = vect_multipl(*vect, poly->direction);
	if (d < 1e-8 && d > -1e-8)
		return (0);
	dist = vect_substr(poly->pos_a, *start_pnt);
	t = vect_multipl(dist, poly->direction) / d;
	if (t < 0.000001 || t > 1.0e30)
		return (0);
	dist = vect_multipl_const(*vect, t);
	inters_pnt->x = start_pnt->x + dist.x;
	inters_pnt->y = start_pnt->y + dist.y;
	inters_pnt->z = start_pnt->z + dist.z;
	if (!(check_poly(poly, inters_pnt)))
		return (0);
	return (1);
}

t_col				get_col_poly(const void *data,
							const t_vect *inters_pnt)
{
	const t_poly	*poly;

	(void)inters_pnt;
	poly = (t_poly *)data;
	return (poly->color);
}

void				destruct_poly(void *data)
{
	t_poly			*poly;

	poly = (t_poly *)data;
	free(poly);
}

t_vect				get_norm_poly(t_poly *poly)
{
	t_vect			res;
	t_vect			a;
	t_vect			b;

	a = vect_substr(poly->pos_b, poly->pos_a);
	b = vect_substr(poly->pos_c, poly->pos_a);
	res = (vector_cross(a, b));
	vect_normalise(&res);
	return (res);
}

t_obj				*new_pol(t_vect pos_a, t_vect pos_b,
								t_vect pos_c, t_col col)
{
	t_obj			*obj;
	t_poly			*poly;

	poly = ft_memalloc(sizeof(*poly));
	poly->pos_a = pos_a;
	poly->pos_b = pos_b;
	poly->pos_c = pos_c;
	poly->color = col;
	poly->direction = get_norm_poly(poly);
	vect_normalise(&poly->direction);
	obj = ft_memalloc(sizeof(*obj));
	obj->data = (void *)poly;
	((t_poly*)obj->data)->obj = obj;
	obj->type = 4;
	obj->intersect = intersect_poly;
	obj->get_col = get_col_poly;
	obj->destruct_data = destruct_poly;
	obj->get_norm_vect = get_norm_vect_poly;
	return (obj);
}
