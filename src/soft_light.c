/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 03:15:43 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/02/27 15:02:05 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_vecarr				compute_soft_light(t_bid_list *lights, t_vecarr struc,
						t_vect *inters_pnt, const t_obj *obj)
{
	t_vect				l_pos[4];

	struc.d.z = 0;
	l_pos[0] = new_v(((t_light *)lights->data)->pos.x -
		((t_light *)lights->data)->radius, ((t_light *)lights->data)->pos.y,
		((t_light *)lights->data)->pos.z - ((t_light *)lights->data)->radius);
	l_pos[1] = vect_substr(new_v(l_pos[0].x, l_pos[0].y,
		l_pos[0].z + ((t_light *)lights->data)->radius * 2), l_pos[0]);
	l_pos[2] = vect_substr(new_v(l_pos[0].x + ((t_light *)lights->data)->radius
			* 2, l_pos[0].y, l_pos[0].z), l_pos[0]);
	struc.a = vect_substr(((t_light *)lights->data)->pos, *inters_pnt);
	while (struc.d.z < 51)
	{
		struc.d.x = ((double)rand() / ((double)RAND_MAX));
		struc.d.y = ((double)rand() / ((double)RAND_MAX));
		l_pos[3] = vect_sum(l_pos[0], vect_multipl_const(l_pos[1], struc.d.x));
		l_pos[3] = vect_sum(l_pos[3], vect_multipl_const(l_pos[2], struc.d.y));
		struc.a = vect_substr(l_pos[3], *inters_pnt);
		if (find_shedow(inters_pnt, obj->scene, obj, struc.a))
			struc.b.x++;
		struc.d.z++;
	}
	return (struc);
}

t_vecarr				check_soft_light(t_bid_list *lights, t_vect *inters_pnt,
									const t_obj *obj, t_vecarr struc)
{
	if (struc.b.x == 0)
	{
		vect_normalise(&struc.a);
		struc.c = obj->get_norm_vect(obj->data, inters_pnt);
		struc.b.y += fmax(vect_multipl(struc.a, struc.c), 0);
		struc.a = vect_substr(((t_light *)lights->data)->pos, *inters_pnt);
		vect_normalise(&struc.a);
		struc.c = obj->get_norm_vect(obj->data, inters_pnt);
		struc.k2.y = fmax(vect_multipl(struc.a, struc.c), 0);
	}
	else
	{
		struc.b.x = struc.b.x / 50;
		struc.b.x = 1 - struc.b.x;
		struc.b.y = struc.b.x;
		vect_normalise(&struc.a);
		struc.c = obj->get_norm_vect(obj->data, inters_pnt);
		struc.k2.y = fmax(vect_multipl(struc.a, struc.c), 0);
		if (struc.k2.y < struc.b.y)
			struc.b.y = struc.k2.y;
	}
	struc.b.y = (struc.b.y + struc.k2.y) / 2;
	struc.b.z = 0;
	return (struc);
}

double					cycle_shadow(const t_obj *obj, const t_vect *inters_pnt,
									t_vect light_ray, double light_ray_len)
{
	t_obj				*obj_shed;
	t_vecarr			flag_dark_intpsh;
	t_bid_list			*objs;

	flag_dark_intpsh.a = new_v(0, 0, 0);
	objs = obj->scene->objs;
	while (objs)
	{
		obj_shed = (t_obj *)objs->data;
		if ((obj_shed->intersect(obj_shed, inters_pnt, &light_ray,
									&flag_dark_intpsh.b)))
		{
			if (light_ray_len >
					vect_len(vect_substr(*inters_pnt, flag_dark_intpsh.b)))
				flag_dark_intpsh = find_shad(obj, obj_shed, flag_dark_intpsh);
		}
		objs = objs->next;
	}
	if (flag_dark_intpsh.a.y == 1)
		flag_dark_intpsh.a.x = 1;
	return (flag_dark_intpsh.a.x);
}

t_vecarr				trans_shadow(t_vecarr struc,
									const t_obj *obj, t_vect *inters_pnt)
{
	double				flag;
	t_vect				reflect_ray;
	t_vect				normal;

	flag = find_shedow(inters_pnt, obj->scene, obj, struc.a);
	vect_normalise(&struc.a);
	normal = obj->get_norm_vect(obj->data, inters_pnt);
	if ((obj->type == 4 || obj->type == 5 || obj->type == 0)
		&& vect_multipl(normal, struc.a) < 0)
		normal = vect_multipl_const(normal, -1);
	reflect_ray = get_reflect_ray(&struc.d, &normal);
	if (flag == 0)
		struc.b.y = (struc.b.y + fmax(vect_multipl(struc.a, normal), 0));
	else if (flag > 1)
		struc.b.y = (struc.b.y + fmax(vect_multipl(struc.a, normal), 0) /
								flag);
	if (obj->refl == 1 && obj->refr == 1 && vect_multipl(reflect_ray, struc.a)
											> 0 && flag == 0)
	{
		struc.b.z += fmax(pow(vect_multipl(reflect_ray, struc.a), 10), 0);
	}
	return (struc);
}

t_vecarr				spotlight(t_bid_list *lights, const t_obj *obj,
						t_vect *inters_pnt, t_vecarr struc)
{
	double				cos_spot;
	t_vect				normal;
	t_vect				reflect_ray;

	vect_normalise(&struc.a);
	cos_spot = vect_multipl(struc.a, ((t_light *)lights->data)->direction);
	cos_spot = acos(cos_spot);
	if (cos_spot <= ((((t_light *)lights->data)->radius * M_PI) / 180) / 2)
	{
		normal = obj->get_norm_vect(obj->data, inters_pnt);
		if (!obj->type && vect_multipl(normal, struc.a) < 0)
			normal = vect_multipl_const(normal, -1);
		reflect_ray = get_reflect_ray(&struc.d, &normal);
		struc.b.y += fmax(vect_multipl(struc.a, normal), 0);
		if (obj->refl == 1 && obj->refr == 1 && vect_multipl(reflect_ray,
			struc.a) > 0)
			struc.b.z += fmax(pow(vect_multipl(reflect_ray, struc.a), 10), 0);
	}
	return (struc);
}
