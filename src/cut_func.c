/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 23:43:45 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/10/24 23:43:47 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double				cut_sphere(t_vect t_t1_t2, const t_vect *start_pnt,
					const t_vect *vect, void *data)
{
	t_vect			x_xx_t;
	t_sphere		*sphere;

	sphere = (t_sphere *)data;
	if (sphere->cut.type == 1)
	{
		x_xx_t = cut_sphere_helper_one(t_t1_t2, sphere, vect, start_pnt);
		if (sphere->cut.cut_min == 0 && sphere->cut.cut_max == 0)
		{
			if (t_t1_t2.x < t_t1_t2.y)
				x_xx_t.z = t_t1_t2.x < 0.000001 ? t_t1_t2.y : t_t1_t2.x;
			else
				x_xx_t.z = t_t1_t2.y < 0.000001 ? t_t1_t2.x : t_t1_t2.y;
			return (x_xx_t.z);
		}
		if (check_sphere_cut(sphere, x_xx_t) == 1)
			return (t_t1_t2.x);
		if (check_sphere_cut(sphere, x_xx_t) == 2)
			return (t_t1_t2.y);
		return (0);
	}
	return (t_t1_t2.x);
}

double				cut_cone(t_vect t_t1_t2, const t_vect *start_pnt,
					const t_vect *vect, void *data)
{
	t_vect			x_xx_t;
	t_cone			*cone;

	cone = (t_cone *)data;
	if (cone->cut.type == 1)
	{
		x_xx_t = cut_cone_helper_one(t_t1_t2, cone, vect, start_pnt);
		if (cone->cut.cut_min == 0 && cone->cut.cut_max == 0)
		{
			if (t_t1_t2.x < t_t1_t2.y)
				x_xx_t.z = t_t1_t2.x < 0.000001 ? t_t1_t2.y : t_t1_t2.x;
			else
				x_xx_t.z = t_t1_t2.y < 0.000001 ? t_t1_t2.x : t_t1_t2.y;
			return (x_xx_t.z);
		}
		if (check_cone_cut(cone, x_xx_t) == 1)
			return (t_t1_t2.x);
		if (check_cone_cut(cone, x_xx_t) == 2)
			return (t_t1_t2.y);
		return (0);
	}
	return (t_t1_t2.x);
}

double				cut_cylinder(t_vect t_t1_t2, const t_vect *start_pnt,
					const t_vect *vect, void *data)
{
	t_vect			x_xx_t;
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)data;
	if (cylinder->cut.type == 1)
	{
		x_xx_t = cut_cylinder_helper_one(t_t1_t2, cylinder, vect, start_pnt);
		if (cylinder->cut.cut_min == 0 && cylinder->cut.cut_max == 0)
		{
			if (t_t1_t2.x < t_t1_t2.y)
				x_xx_t.z = t_t1_t2.x < 0.000001 ? t_t1_t2.y : t_t1_t2.x;
			else
				x_xx_t.z = t_t1_t2.y < 0.000001 ? t_t1_t2.x : t_t1_t2.y;
			return (x_xx_t.z);
		}
		if (check_cylinder_cut(cylinder, x_xx_t) == 1)
			return (t_t1_t2.x);
		if (check_cylinder_cut(cylinder, x_xx_t) == 2)
			return (t_t1_t2.y);
		return (0);
	}
	return (t_t1_t2.x);
}

double				cut_elips(t_vect t_t1_t2, const t_vect *start_pnt,
					const t_vect *vect, void *data)
{
	t_vect			x_xx_t;
	t_elips			*elips;

	elips = (t_elips *)data;
	if (elips->cut.type == 1)
	{
		x_xx_t = cut_elips_helper_one(t_t1_t2, elips, vect, start_pnt);
		if (elips->cut.cut_min == 0 && elips->cut.cut_max == 0)
		{
			if (t_t1_t2.x < t_t1_t2.y)
				x_xx_t.z = t_t1_t2.x < 0.000001 ? t_t1_t2.y : t_t1_t2.x;
			else
				x_xx_t.z = t_t1_t2.y < 0.000001 ? t_t1_t2.x : t_t1_t2.y;
			return (x_xx_t.z);
		}
		if (check_elips_cut(elips, x_xx_t) == 1)
			return (t_t1_t2.x);
		if (check_elips_cut(elips, x_xx_t) == 2)
			return (t_t1_t2.y);
		return (0);
	}
	return (t_t1_t2.x);
}

double				cut_parab(t_vect t_t1_t2, const t_vect *start_pnt,
					const t_vect *vect, void *data)
{
	t_vect			x_xx_t;
	t_parab			*parab;

	parab = (t_parab *)data;
	if (parab->cut.type == 1)
	{
		x_xx_t = cut_parab_helper_one(t_t1_t2, parab, vect, start_pnt);
		if (parab->cut.cut_min == 0 && parab->cut.cut_max == 0)
		{
			if (t_t1_t2.x < t_t1_t2.y)
				x_xx_t.z = t_t1_t2.x < 0.000001 ? t_t1_t2.y : t_t1_t2.x;
			else
				x_xx_t.z = t_t1_t2.y < 0.000001 ? t_t1_t2.x : t_t1_t2.y;
			return (x_xx_t.z);
		}
		if (check_parab_cut(parab, x_xx_t) == 1)
			return (t_t1_t2.x);
		if (check_parab_cut(parab, x_xx_t) == 2)
			return (t_t1_t2.y);
		return (0);
	}
	return (t_t1_t2.x);
}
