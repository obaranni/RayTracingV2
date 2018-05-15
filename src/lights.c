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

unsigned int		get_int_col(const t_obj *obj, double *k,
									const t_vect *inters_pnt)
{
	t_col			col;
	unsigned int	int_col;
	double			amb;

	amb = obj->scene->amb;
	col = obj->get_col(obj->data, inters_pnt);
	if (obj->scene->cartoon_flag == 1)
		k = set_cartoon_filter(k);
	col.r = (unsigned char)fmin(fmax(col.r *
									(k[0] + amb) + k[1] * 255, 0), 255);
	col.g = (unsigned char)fmin(fmax(col.g *
									(k[0] + amb) + k[1] * 255, 0), 255);
	col.b = (unsigned char)fmin(fmax(col.b *
									(k[0] + amb) + k[1] * 255, 0), 255);
	if (obj->scene->sepia_flag == 1)
		set_sepia_filter(&col);
	int_col = (unsigned int)ft_rgb_to_int(col.r, col.g, col.b);
	*((guchar *)&int_col + 0) = col.r;
	*((guchar *)&int_col + 1) = col.g;
	*((guchar *)&int_col + 2) = col.b;
	free(k);
	return (int_col);
}

double				find_shedow(const t_vect *inters_pnt, const t_scene *scene,
							const t_obj *obj, t_vect light_ray)
{
	double			flag;
	double			light_ray_len;
	t_bid_list		*lights;

	lights = scene->lights;
	if (((t_light *)lights->data)->type == 1)
		light_ray_len = INFINITY;
	else
	{
		light_ray_len = vect_len(light_ray);
		vect_normalise(&light_ray);
	}
	flag = cycle_shadow(obj, inters_pnt, light_ray, light_ray_len);
	return (flag);
}

t_vecarr			check_spot_soft(const t_obj *obj, t_vect *inters_pnt,
									t_bid_list *lights, t_vecarr struc)
{
	if (((t_light *)lights->data)->type == 2)
	{
		struc.a = vect_substr(((t_light *)lights->data)->pos, *inters_pnt);
		if (!find_shedow(inters_pnt, obj->scene, obj, struc.a))
			struc = spotlight(lights, obj, inters_pnt, struc);
	}
	if (((t_light *)lights->data)->type == 3)
	{
		struc.b.x = 0;
		struc = compute_soft_light(lights, struc, inters_pnt, obj);
		struc = check_soft_light(lights, inters_pnt, obj, struc);
		struc.a = vect_substr(((t_light *)lights->data)->pos, *inters_pnt);
		if (vect_multipl(((t_light *)lights->data)->direction, struc.a) > 0)
		{
			struc.b.y = 0;
			struc.b.z = 0;
		}
	}
	return (struc);
}

t_vecarr			find_light_ray(t_bid_list *lights,
					t_vecarr struc, t_vect *inters_pnt)
{
	if (((t_light *)lights->data)->type == 0)
		struc.a = vect_substr(((t_light *)lights->data)->pos,
							*inters_pnt);
	else if (((t_light *)lights->data)->type == 1)
		struc.a = ((t_light *)lights->data)->direction;
	return (struc);
}

int					find_lights(t_vect *dirr, const t_obj *obj,
								t_vect *inters_pnt, const t_scene *scene)
{
	t_bid_list		*lights;
	double			*k;
	t_vecarr		struc;

	ft_bzero(&struc, sizeof(struc));
	struc.d = *dirr;
	k = ft_memalloc(sizeof(double) * 2);
	lights = scene->lights;
	while (lights)
	{
		struc.b.y = k[0];
		struc.b.z = k[1];
		if (((t_light *)lights->data)->type == 0 ||
			((t_light *)lights->data)->type == 1)
		{
			struc = find_light_ray(lights, struc, inters_pnt);
			struc = trans_shadow(struc, obj, inters_pnt);
			k[0] += struc.b.y;
			k[1] += struc.b.z;
		}
		k[0] = (check_spot_soft(obj, inters_pnt, lights, struc)).b.y;
		k[1] = (check_spot_soft(obj, inters_pnt, lights, struc)).b.z;
		lights = lights->next;
	}
	return (get_int_col(obj, k, inters_pnt));
}
