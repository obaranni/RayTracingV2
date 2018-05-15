/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:25:07 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/10/30 03:25:09 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					intersect_cone(t_obj *obj,
									const t_vect *start_pnt,
									const t_vect *vect,
									t_vect *inters_pnt)
{
	const t_cone	*cone;
	double			t;
	t_vect			dist;
	t_vect			a_b_c;

	cone = (t_cone *)obj->data;
	dist = vect_substr(*start_pnt, cone->position);
	a_b_c.x = vect_multipl(*vect, *vect) - (1 + pow(tan(cone->angel), 2))
				* pow(vect_multipl(*vect, cone->direction), 2);
	a_b_c.y = 2 * (vect_multipl(*vect, dist) - (1 + pow(tan(cone->angel), 2))
				* vect_multipl(*vect, cone->direction)
				* vect_multipl(dist, cone->direction));
	a_b_c.z = vect_multipl(dist, dist) - (1 + pow(tan(cone->angel), 2))
				* pow(vect_multipl(dist, cone->direction), 2);
	obj->current_col = cone->color;
	if (!check_d(&t, new_vecparr(&a_b_c, start_pnt, vect), obj))
		return (0);
	dist = vect_multipl_const(*vect, t);
	inters_pnt->x = start_pnt->x + dist.x;
	inters_pnt->y = start_pnt->y + dist.y;
	inters_pnt->z = start_pnt->z + dist.z;
	return (1);
}

t_col				get_col_cone(const void *data,
							const t_vect *inters_pnt)
{
	const t_cone	*cone;

	(void)inters_pnt;
	cone = (t_cone *)data;
	return (cone->color);
}

void				destruct_cone(void *data)
{
	t_cone			*cone;

	cone = (t_cone *)data;
	free(cone);
}

t_vect				get_norm_vect_cone(void *data,
											const t_vect *inters_pnt)
{
	t_cone			*cone;
	t_vect			vect;
	t_vect			vect_proj;
	t_vect			res;

	cone = (t_cone *)data;
	vect = vect_substr(*inters_pnt, cone->position);
	vect_proj = vect_multipl_const(cone->direction,
									vect_multipl(vect, cone->direction)
									/ vect_multipl(cone->direction,
													cone->direction));
	res = vect_multipl_const(vect_substr(vect, vect_proj),
								1 + pow(tan(cone->angel), 2));
	vect_normalise(&res);
	return (res);
}

t_obj				*new_cone(t_param param, double angel, t_cut cut)
{
	t_obj			*obj;
	t_cone			*cone;

	cone = ft_memalloc(sizeof(*cone));
	cone->position = param.pos;
	cone->angel = angel;
	cone->color = param.col;
	cone->direction = param.dir;
	cone->cut.type = cut.type;
	cone->cut.axis = cut.axis;
	cone->cut.cut_min = cut.cut_min;
	cone->cut.cut_max = cut.cut_max;
	vect_normalise(&cone->direction);
	obj = ft_memalloc(sizeof(*obj));
	obj->type = 3;
	obj->data = (void *)cone;
	((t_cone*)obj->data)->obj = obj;
	obj->intersect = intersect_cone;
	obj->cut = cut_cone;
	obj->get_col = get_col_cone;
	obj->destruct_data = destruct_cone;
	obj->get_norm_vect = get_norm_vect_cone;
	return (obj);
}
