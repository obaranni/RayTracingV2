/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 23:00:40 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/09/16 23:00:42 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					check_plane_helper(double t1, const t_plane
	*plane, double x)
{
	if (plane->cut.axis == 1 && (x >= plane->position.x +
		plane->cut.cut_min && x <= plane->position.x + plane->cut.cut_max))
		return (1);
	else if (plane->cut.axis == 2 && (x >= plane->position.y +
		plane->cut.cut_min && x <= plane->position.y + plane->cut.cut_max))
		return (1);
	else if (plane->cut.axis == 3 && (x >= plane->position.z +
		plane->cut.cut_min && x <= plane->position.z + plane->cut.cut_max))
		return (1);
	return (0);
}

double				check_plane_cut(double t1,
					const t_vect *start_pnt, const t_vect *vect, void *data)
{
	double			x;
	const t_plane	*plane;

	plane = (t_plane *)data;
	if (plane->cut.type == 1)
	{
		if (plane->cut.axis == 1)
			x = start_pnt->x + t1 * vect->x;
		if (plane->cut.axis == 2)
			x = start_pnt->y + t1 * vect->y;
		if (plane->cut.axis == 3)
			x = start_pnt->z + t1 * vect->z;
		if (plane->cut.cut_min == 0 && plane->cut.cut_max == 0)
			return (t1);
		if (check_plane_helper(t1, plane, x))
			return (t1);
		return (0);
	}
	return (t1);
}
