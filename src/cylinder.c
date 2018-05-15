/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:24:34 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/10/30 03:24:47 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					intersect_cylinder(t_obj *obj,
										const t_vect *start_pnt,
										const t_vect *vect,
										t_vect *inters_pnt)
{
	t_cylinder		*cylinder;
	double			t;
	t_vect			dist;
	t_vect			a_b_c;

	cylinder = (t_cylinder *)obj->data;
	dist = vect_substr(*start_pnt, cylinder->position);
	a_b_c.x = vect_multipl(*vect, *vect)
				- pow(vect_multipl(*vect, cylinder->direction), 2);
	a_b_c.y = 2 * (vect_multipl(*vect, dist)
					- vect_multipl(*vect, cylinder->direction)
					* vect_multipl(dist, cylinder->direction));
	a_b_c.z = vect_multipl(dist, dist)
				- pow((cylinder->radius), 2)
				- pow(vect_multipl(dist, cylinder->direction), 2);
	obj->current_col = cylinder->color;
	if (!check_d(&t, new_vecparr(&a_b_c, start_pnt, vect), obj))
		return (0);
	dist = vect_multipl_const(*vect, t);
	inters_pnt->x = start_pnt->x + dist.x;
	inters_pnt->y = start_pnt->y + dist.y;
	inters_pnt->z = start_pnt->z + dist.z;
	return (1);
}

t_col				get_col_cylinder(const void *data,
										const t_vect *inters_pnt)
{
	t_cylinder		*cylinder;

	(void)inters_pnt;
	cylinder = (t_cylinder *)data;
	return (cylinder->color);
}

void				destruct_cylinder(void *data)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)data;
	free(cylinder);
}

t_vect				get_norm_vect_cylinder(void *data,
											const t_vect *inters_pnt)
{
	t_cylinder		*cylinder;
	t_vect			vect;
	t_vect			vect_proj;
	t_vect			res;

	cylinder = (t_cylinder *)data;
	vect = vect_substr(*inters_pnt, cylinder->position);
	vect_proj = vect_multipl_const(cylinder->direction,
								vect_multipl(vect, cylinder->direction));
	res = vect_substr(vect, vect_proj);
	vect_normalise(&res);
	return (res);
}

t_obj				*new_cylinder(t_param param, double r, t_cut cut)
{
	t_obj			*obj;
	t_cylinder		*cylinder;

	cylinder = ft_memalloc(sizeof(*cylinder));
	cylinder->position = param.pos;
	cylinder->radius = r;
	cylinder->color = param.col;
	cylinder->direction = param.dir;
	cylinder->cut.type = cut.type;
	cylinder->cut.axis = cut.axis;
	cylinder->cut.cut_min = cut.cut_min;
	cylinder->cut.cut_max = cut.cut_max;
	vect_normalise(&cylinder->direction);
	obj = ft_memalloc(sizeof(*obj));
	obj->data = (void *)cylinder;
	((t_cylinder*)obj->data)->obj = obj;
	obj->type = 2;
	obj->intersect = intersect_cylinder;
	obj->cut = cut_cylinder;
	obj->get_col = get_col_cylinder;
	obj->destruct_data = destruct_cylinder;
	obj->get_norm_vect = get_norm_vect_cylinder;
	return (obj);
}
