/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:11:33 by obaranni          #+#    #+#             */
/*   Updated: 2018/02/27 13:57:32 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double			get_min_t(t_obj **obj, t_obj *obj_cur, double cur_t)
{
	*obj = obj_cur;
	return (cur_t);
}

double			find_closest_obj(t_scene *scene, t_obj **obj,
									t_vect ray_start_point, t_vecparr2 v)
{
	t_bid_list	*objs;
	t_obj		*obj_cur;
	t_vect		inters_pnt_cur;
	double		min_t;
	double		cur_t;

	objs = scene->objs;
	*obj = NULL;
	min_t = 1.0e30;
	while (objs)
	{
		obj_cur = (t_obj *)objs->data;
		if (obj_cur->intersect(obj_cur, &ray_start_point,
								v.dirr, &inters_pnt_cur))
		{
			cur_t = vect_len(vect_substr(inters_pnt_cur, ray_start_point));
			if (cur_t < min_t)
			{
				min_t = get_min_t(obj, obj_cur, cur_t);
				*v.inters_pnt = inters_pnt_cur;
			}
		}
		objs = objs->next;
	}
	return (min_t);
}
