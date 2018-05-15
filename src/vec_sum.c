/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:39:53 by obaranni          #+#    #+#             */
/*   Updated: 2018/02/27 14:03:07 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_vect			ft_vec_sum(t_vect v1, t_vect v2)
{
	v1.x = v1.x + v2.x;
	v1.y = v1.y + v2.y;
	v1.z = v1.z + v2.z;
	return (v1);
}

t_vect			ft_vec_mul_scal(t_vect v, double n)
{
	v.x = v.x * n;
	v.y = v.y * n;
	v.z = v.z * n;
	return (v);
}
