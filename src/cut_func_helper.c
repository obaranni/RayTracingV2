/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_func_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 23:00:40 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/09/16 23:00:42 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					check_sphere_cut(t_sphere *sphere, const t_vect x_xx_t)
{
	if (sphere->cut.axis == 1 && (x_xx_t.y >= sphere->position.x +
		sphere->cut.cut_min && x_xx_t.y <= sphere->position.x +
		sphere->cut.cut_max))
		return (2);
	else if (sphere->cut.axis == 1 && (x_xx_t.x >= sphere->position.x +
		sphere->cut.cut_min && x_xx_t.x <= sphere->position.x +
		sphere->cut.cut_max))
		return (1);
	else if (sphere->cut.axis == 2 && (x_xx_t.y >= sphere->position.y +
		sphere->cut.cut_min && x_xx_t.y <= sphere->position.y +
		sphere->cut.cut_max))
		return (2);
	else if (sphere->cut.axis == 2 && (x_xx_t.x >= sphere->position.y +
		sphere->cut.cut_min && x_xx_t.x <= sphere->position.y +
		sphere->cut.cut_max))
		return (1);
	else if (sphere->cut.axis == 3 && (x_xx_t.y >= sphere->position.z +
		sphere->cut.cut_min && x_xx_t.y <= sphere->position.z +
		sphere->cut.cut_max))
		return (2);
	else if (sphere->cut.axis == 3 && (x_xx_t.x >= sphere->position.z +
		sphere->cut.cut_min && x_xx_t.x <= sphere->position.z +
		sphere->cut.cut_max))
		return (1);
	return (-1);
}

int					check_elips_cut(t_elips *elips, const t_vect x_xx_t)
{
	if (elips->cut.axis == 1 && (x_xx_t.y >= elips->position.x +
		elips->cut.cut_min && x_xx_t.y <= elips->position.x +
		elips->cut.cut_max))
		return (2);
	else if (elips->cut.axis == 1 && (x_xx_t.x >= elips->position.x +
		elips->cut.cut_min && x_xx_t.x <= elips->position.x +
		elips->cut.cut_max))
		return (1);
	else if (elips->cut.axis == 2 && (x_xx_t.y >= elips->position.y +
		elips->cut.cut_min && x_xx_t.y <= elips->position.y +
		elips->cut.cut_max))
		return (2);
	else if (elips->cut.axis == 2 && (x_xx_t.x >= elips->position.y +
		elips->cut.cut_min && x_xx_t.x <= elips->position.y +
		elips->cut.cut_max))
		return (1);
	else if (elips->cut.axis == 3 && (x_xx_t.y >= elips->position.z +
		elips->cut.cut_min && x_xx_t.y <= elips->position.z +
		elips->cut.cut_max))
		return (2);
	else if (elips->cut.axis == 3 && (x_xx_t.x >= elips->position.z +
		elips->cut.cut_min && x_xx_t.x <= elips->position.z +
		elips->cut.cut_max))
		return (1);
	return (-1);
}

t_vect				cut_elips_helper_one(t_vect t_t1_t2, t_elips *elips,
					const t_vect *vect, const t_vect *start_pnt)
{
	t_vect			x_xx_t;

	if (elips->cut.axis == 1)
	{
		x_xx_t.x = start_pnt->x + t_t1_t2.x * vect->x;
		x_xx_t.y = start_pnt->x + t_t1_t2.y * vect->x;
	}
	if (elips->cut.axis == 2)
	{
		x_xx_t.x = start_pnt->y + t_t1_t2.x * vect->y;
		x_xx_t.y = start_pnt->y + t_t1_t2.y * vect->y;
	}
	if (elips->cut.axis == 3)
	{
		x_xx_t.x = start_pnt->z + t_t1_t2.x * vect->z;
		x_xx_t.y = start_pnt->z + t_t1_t2.y * vect->z;
	}
	return (x_xx_t);
}

int					check_parab_cut(t_parab *parab, const t_vect x_xx_t)
{
	if (parab->cut.axis == 1 && (x_xx_t.y >= parab->position.x +
		parab->cut.cut_min && x_xx_t.y <= parab->position.x +
		parab->cut.cut_max))
		return (2);
	else if (parab->cut.axis == 1 && (x_xx_t.x >= parab->position.x +
		parab->cut.cut_min && x_xx_t.x <= parab->position.x +
		parab->cut.cut_max))
		return (1);
	else if (parab->cut.axis == 2 && (x_xx_t.y >= parab->position.y +
		parab->cut.cut_min && x_xx_t.y <= parab->position.y +
		parab->cut.cut_max))
		return (2);
	else if (parab->cut.axis == 2 && (x_xx_t.x >= parab->position.y +
		parab->cut.cut_min && x_xx_t.x <= parab->position.y +
		parab->cut.cut_max))
		return (1);
	else if (parab->cut.axis == 3 && (x_xx_t.y >= parab->position.z +
		parab->cut.cut_min && x_xx_t.y <= parab->position.z +
		parab->cut.cut_max))
		return (2);
	else if (parab->cut.axis == 3 && (x_xx_t.x >= parab->position.z +
		parab->cut.cut_min && x_xx_t.x <= parab->position.z +
		parab->cut.cut_max))
		return (1);
	return (-1);
}

t_vect				cut_parab_helper_one(t_vect t_t1_t2, t_parab
					*parab, const t_vect *vect, const t_vect *start_pnt)
{
	t_vect x_xx_t;

	x_xx_t = new_v(0, 0, 0);
	if (parab->cut.axis == 1)
	{
		x_xx_t.x = start_pnt->x + t_t1_t2.x * vect->x;
		x_xx_t.y = start_pnt->x + t_t1_t2.y * vect->x;
	}
	if (parab->cut.axis == 2)
	{
		x_xx_t.x = start_pnt->y + t_t1_t2.x * vect->y;
		x_xx_t.y = start_pnt->y + t_t1_t2.y * vect->y;
	}
	if (parab->cut.axis == 3)
	{
		x_xx_t.x = start_pnt->z + t_t1_t2.x * vect->z;
		x_xx_t.y = start_pnt->z + t_t1_t2.y * vect->z;
	}
	return (x_xx_t);
}
