/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_func_helper_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 23:00:40 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/09/16 23:00:42 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_vect				cut_sphere_helper_one(t_vect t_t1_t2, t_sphere *sphere,
									const t_vect *vect, const t_vect *start_pnt)
{
	t_vect x_xx_t;

	if (sphere->cut.axis == 1)
	{
		x_xx_t.x = start_pnt->x + t_t1_t2.x * vect->x;
		x_xx_t.y = start_pnt->x + t_t1_t2.y * vect->x;
	}
	if (sphere->cut.axis == 2)
	{
		x_xx_t.x = start_pnt->y + t_t1_t2.x * vect->y;
		x_xx_t.y = start_pnt->y + t_t1_t2.y * vect->y;
	}
	if (sphere->cut.axis == 3)
	{
		x_xx_t.x = start_pnt->z + t_t1_t2.x * vect->z;
		x_xx_t.y = start_pnt->z + t_t1_t2.y * vect->z;
	}
	return (x_xx_t);
}

int					check_cylinder_cut(t_cylinder *cylinder,
										const t_vect x_xx_t)
{
	if (cylinder->cut.axis == 1 && (x_xx_t.y >= cylinder->position.x +
		cylinder->cut.cut_min && x_xx_t.y <= cylinder->position.x +
		cylinder->cut.cut_max))
		return (2);
	else if (cylinder->cut.axis == 1 && (x_xx_t.x >= cylinder->position.x +
		cylinder->cut.cut_min && x_xx_t.x <= cylinder->position.x +
		cylinder->cut.cut_max))
		return (1);
	else if (cylinder->cut.axis == 2 && (x_xx_t.y >= cylinder->position.y +
		cylinder->cut.cut_min && x_xx_t.y <= cylinder->position.y +
		cylinder->cut.cut_max))
		return (2);
	else if (cylinder->cut.axis == 2 && (x_xx_t.x >= cylinder->position.y +
		cylinder->cut.cut_min && x_xx_t.x <= cylinder->position.y +
		cylinder->cut.cut_max))
		return (1);
	else if (cylinder->cut.axis == 3 && (x_xx_t.y >= cylinder->position.z +
		cylinder->cut.cut_min && x_xx_t.y <= cylinder->position.z +
		cylinder->cut.cut_max))
		return (2);
	else if (cylinder->cut.axis == 3 && (x_xx_t.x >= cylinder->position.z +
		cylinder->cut.cut_min && x_xx_t.x <= cylinder->position.z +
		cylinder->cut.cut_max))
		return (1);
	return (-1);
}

t_vect				cut_cylinder_helper_one(t_vect t_t1_t2, t_cylinder
						*cylinder, const t_vect *vect, const t_vect *start_pnt)
{
	t_vect x_xx_t;

	if (cylinder->cut.axis == 1)
	{
		x_xx_t.x = start_pnt->x + t_t1_t2.x * vect->x;
		x_xx_t.y = start_pnt->x + t_t1_t2.y * vect->x;
	}
	if (cylinder->cut.axis == 2)
	{
		x_xx_t.x = start_pnt->y + t_t1_t2.x * vect->y;
		x_xx_t.y = start_pnt->y + t_t1_t2.y * vect->y;
	}
	if (cylinder->cut.axis == 3)
	{
		x_xx_t.x = start_pnt->z + t_t1_t2.x * vect->z;
		x_xx_t.y = start_pnt->z + t_t1_t2.y * vect->z;
	}
	return (x_xx_t);
}

int					check_cone_cut(t_cone *cone, const t_vect x_xx_t)
{
	if (cone->cut.axis == 1 && (x_xx_t.y >= cone->position.x +
		cone->cut.cut_min && x_xx_t.y <= cone->position.x +
		cone->cut.cut_max))
		return (2);
	else if (cone->cut.axis == 1 && (x_xx_t.x >= cone->position.x +
			cone->cut.cut_min && x_xx_t.x <= cone->position.x +
			cone->cut.cut_max))
		return (1);
	else if (cone->cut.axis == 2 && (x_xx_t.y >= cone->position.y +
			cone->cut.cut_min && x_xx_t.y <= cone->position.y +
			cone->cut.cut_max))
		return (2);
	else if (cone->cut.axis == 2 && (x_xx_t.x >= cone->position.y +
			cone->cut.cut_min && x_xx_t.x <= cone->position.y +
			cone->cut.cut_max))
		return (1);
	else if (cone->cut.axis == 3 && (x_xx_t.y >= cone->position.z +
			cone->cut.cut_min && x_xx_t.y <= cone->position.z +
			cone->cut.cut_max))
		return (2);
	else if (cone->cut.axis == 3 && (x_xx_t.x >= cone->position.z +
			cone->cut.cut_min && x_xx_t.x <= cone->position.z +
			cone->cut.cut_max))
		return (1);
	return (-1);
}

t_vect				cut_cone_helper_one(t_vect t_t1_t2, t_cone *cone,
					const t_vect *vect, const t_vect *start_pnt)
{
	t_vect x_xx_t;

	if (cone->cut.axis == 1)
	{
		x_xx_t.x = start_pnt->x + t_t1_t2.x * vect->x;
		x_xx_t.y = start_pnt->x + t_t1_t2.y * vect->x;
	}
	if (cone->cut.axis == 2)
	{
		x_xx_t.x = start_pnt->y + t_t1_t2.x * vect->y;
		x_xx_t.y = start_pnt->y + t_t1_t2.y * vect->y;
	}
	if (cone->cut.axis == 3)
	{
		x_xx_t.x = start_pnt->z + t_t1_t2.x * vect->z;
		x_xx_t.y = start_pnt->z + t_t1_t2.y * vect->z;
	}
	return (x_xx_t);
}
