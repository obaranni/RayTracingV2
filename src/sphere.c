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

int					intersect_sphere(t_obj *obj, const t_vect *start_pnt,
									const t_vect *vect, t_vect *inters_pnt)
{
	const t_sphere	*sphere;
	double			t;
	t_vect			dist;
	t_vect			a_b_c;

	sphere = (t_sphere *)obj->data;
	a_b_c.x = vect_multipl(*vect, *vect);
	dist = vect_substr(*start_pnt, sphere->position);
	a_b_c.y = 2 * vect_multipl(*vect, dist);
	a_b_c.z = vect_multipl(dist, dist)
			- sphere->radius * sphere->radius;
	obj->current_col = sphere->color;
	if (!check_d(&t, new_vecparr(&a_b_c, start_pnt, vect), obj))
		return (0);
	dist = vect_multipl_const(*vect, t);
	inters_pnt->x = start_pnt->x + dist.x;
	inters_pnt->y = start_pnt->y + dist.y;
	inters_pnt->z = start_pnt->z + dist.z;
	return (1);
}

t_col				get_col_sphere(const void *data,
							const t_vect *inters_pnt)
{
	const t_sphere	*sphere;

	(void)inters_pnt;
	sphere = (t_sphere *)data;
	return (sphere->color);
}

void				destruct_sphere(void *data)
{
	t_sphere		*sphere;

	sphere = (t_sphere *)data;
	free(sphere);
}

t_vect				get_norm_vect_sphere(void *data,
											const t_vect *inters_pnt)
{
	t_sphere		*sphere;
	t_vect			vect;

	sphere = (t_sphere *)data;
	vect = vect_substr(*inters_pnt, sphere->position);
	vect_normalise(&vect);
	return (vect);
}

t_obj				*new_sphere(t_vect pos, double r, t_col col, t_cut cut)
{
	t_obj			*obj;
	t_sphere		*sphere;

	sphere = ft_memalloc(sizeof(*sphere));
	sphere->position = pos;
	sphere->radius = r;
	sphere->color = col;
	sphere->cut.type = cut.type;
	sphere->cut.axis = cut.axis;
	sphere->cut.cut_min = cut.cut_min;
	sphere->cut.cut_max = cut.cut_max;
	sphere->dir = new_v(0, 0, 1);
	obj = ft_memalloc(sizeof(*obj));
	obj->data = (void *)sphere;
	((t_sphere*)obj->data)->obj = obj;
	obj->type = 1;
	obj->intersect = intersect_sphere;
	obj->cut = cut_sphere;
	obj->get_col = get_col_sphere;
	obj->destruct_data = destruct_sphere;
	obj->get_norm_vect = get_norm_vect_sphere;
	return (obj);
}
