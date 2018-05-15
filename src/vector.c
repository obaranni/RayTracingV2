/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:28:30 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/02/27 14:03:30 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double		vect_multipl(t_vect a, t_vect b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vect		vect_multipl_const(const t_vect a, const double c)
{
	t_vect	res;

	res.x = a.x * c;
	res.y = a.y * c;
	res.z = a.z * c;
	return (res);
}

double		vect_len(t_vect v)
{
	return (sqrt(vect_multipl(v, v)));
}

t_vect		vect_substr(t_vect end, t_vect start)
{
	t_vect	res;

	res.x = end.x - start.x;
	res.y = end.y - start.y;
	res.z = end.z - start.z;
	return (res);
}

t_vect		new_v(double x, double y, double z)
{
	t_vect	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}
