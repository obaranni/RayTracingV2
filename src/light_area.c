/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_area.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:36:08 by obaranni          #+#    #+#             */
/*   Updated: 2018/03/25 13:30:37 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double				check_areal_cut(double t1, const t_vect *start_pnt,
					const t_vect *vect, t_light *areal)
{
	double			x;
	double			z;

	if (areal->radius == 0)
		return (t1);
	x = start_pnt->x + t1 * vect->x;
	z = start_pnt->z + t1 * vect->z;
	if (x > (areal->pos.x - areal->radius) &&
		x < areal->radius + areal->pos.x && z > (areal->pos.z - areal->radius)
				&& z < areal->radius + areal->pos.z)
		return (t1);
	return (0);
}

int					intersect_areal(t_light *areal,
		const t_vect *start_pnt, const t_vect *vect, t_vect *inters_pnt)
{
	double			d;
	double			t;
	t_vect			dist;

	d = vect_multipl(*vect, areal->direction);
	if (d == 0.0)
		return (0);
	dist = vect_substr(areal->pos, *start_pnt);
	t = vect_multipl(dist, areal->direction) / d;
	t = check_areal_cut(t, start_pnt, vect, areal);
	if (t < 0.000001 || t > 1.0e30)
		return (0);
	dist = vect_multipl_const(*vect, t);
	inters_pnt->x = start_pnt->x + dist.x;
	inters_pnt->y = start_pnt->y + dist.y;
	inters_pnt->z = start_pnt->z + dist.z;
	return (1);
}

t_col				get_col_areal(t_light *lght,
									const t_vect *inters_pnt)
{
	(void)inters_pnt;
	return (lght->color);
}

/*
** void				destruct_disc(void *data)
**{
**    t_disc		*disc;
**
**    disc = (t_disc *)data;
**    free(disc);
**}
*/

t_light				*new_area_light(t_param param, t_vect secondary)
{
	t_light			*areal;

	areal = ft_memalloc(sizeof(*areal));
	areal->pos = param.pos;
	areal->color = param.col;
	areal->direction = param.dir;
	areal->radius = secondary.x;
	areal->intense = secondary.y;
	areal->type = secondary.z;
	vect_normalise(&areal->direction);
	return (areal);
}
