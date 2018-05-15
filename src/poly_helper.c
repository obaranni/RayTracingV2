/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:24:55 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/03/19 22:38:22 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					check_poly(t_poly *poly, t_vect *inters_pnt)
{
	t_vecarr		edge;
	t_vecarr		c;

	edge.a = vect_substr(poly->pos_b, poly->pos_a);
	edge.b = vect_substr(poly->pos_c, poly->pos_b);
	edge.c = vect_substr(poly->pos_a, poly->pos_c);
	c.a = vect_substr(*inters_pnt, poly->pos_a);
	c.b = vect_substr(*inters_pnt, poly->pos_b);
	c.c = vect_substr(*inters_pnt, poly->pos_c);
	if (!(vect_multipl(poly->direction, vector_cross(edge.a, c.a)) > 0 &&
		vect_multipl(poly->direction, vector_cross(edge.b, c.b)) > 0 &&
		vect_multipl(poly->direction, vector_cross(edge.c, c.c)) > 0))
		return (0);
	return (1);
}

t_vect				get_norm_vect_poly(void *data,
										const t_vect *inters_pnt)
{
	t_poly			*poly;
	t_vect			res;
	t_vect			a;
	t_vect			b;

	(void)inters_pnt;
	poly = (t_poly *)data;
	a = vect_substr(poly->pos_b, poly->pos_a);
	b = vect_substr(poly->pos_c, poly->pos_a);
	res = (vector_cross(a, b));
	vect_normalise(&res);
	return (res);
}
