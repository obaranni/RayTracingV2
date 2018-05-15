/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 20:53:44 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/08 20:57:17 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int			is_it_mirror(t_atr *atr, int ref_numb)
{
	t_vect	normal;

	if (atr->q.obj && atr->q.obj->refl >= 0 && atr->q.obj->refl < 1)
	{
		normal = atr->q.obj->get_norm_vect(atr->q.obj->data,
			&(atr->q.inters_pnt));
		vect_normalise(&normal);
		atr->q.dir = vect_substr(atr->q.dir, vect_multipl_const(normal,
			2 * (vect_multipl(normal, atr->q.dir))));
		vect_normalise(&(atr->q.dir));
		return (throw_a_ray(atr, ++ref_numb, atr->q.inters_pnt));
	}
	return (0);
}
