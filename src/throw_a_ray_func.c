/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_a_ray_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:06:58 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/09 15:21:00 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			swap_objects(t_atr *atr, t_vect *this_dir,
		t_vect *inters_pnt)
{
	*this_dir = atr->q.dir;
	*inters_pnt = atr->q.inters_pnt;
}

void			refraction_color(t_atr *atr, t_vect *this_dir,
		t_vect *inters_pnt, t_obj *this)
{
	atr->colors.refr = is_it_glass(atr, atr->ref_numb);
	atr->colors.refr = get_refl_color(find_lights(this_dir, this,
		inters_pnt, atr->scene), atr->colors.refr, this->refr);
	atr->colors.result = get_refl_color(atr->colors.refr,
			atr->colors.refl, this->refl);
}

void			reflection_color(t_atr *atr, t_vect *this_dir,
		t_vect *inters_pnt, t_obj *this)
{
	atr->colors.refl = is_it_mirror(atr, atr->ref_numb);
	atr->colors.refl = get_refl_color(find_lights(this_dir, this,
		inters_pnt, atr->scene), atr->colors.refl, this->refl);
}

int				throw_a_ray(t_atr *atr, int ref_numb, t_vect ray_start_point)
{
	t_vect		this_dir;
	t_vect		inters_pnt;
	t_obj		*this;

	if (ref_numb > atr->scene->specularity)
		return (0);
	find_closest_obj(atr->scene, &(atr->q.obj), ray_start_point,
					new_vecparr2(&(atr->q.inters_pnt), &(atr->q.dir)));
	if (atr->q.obj)
	{
		this = atr->q.obj;
		swap_objects(atr, &this_dir, &inters_pnt);
		atr->ref_numb = ref_numb;
		reflection_color(atr, &this_dir, &inters_pnt, this);
		atr->q.obj = this;
		atr->q.dir = this_dir;
		atr->q.inters_pnt = inters_pnt;
		if (atr->q.obj->refr < 1)
			refraction_color(atr, &this_dir, &inters_pnt, this);
		else
			atr->colors.result = atr->colors.refl;
		if (this)
			return (atr->colors.result);
	}
	return (0);
}
