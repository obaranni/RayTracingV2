/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 03:15:43 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/02/27 15:02:05 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double			*set_cartoon_filter(double *k)
{
	if (k[0] > 0 && k[0] <= 0.3)
		k[0] = 0.3;
	if (k[0] > 0.3 && k[0] <= 0.7)
		k[0] = 0.6;
	if (k[0] > 0.7 && k[0] <= 1)
		k[0] = 0.9;
	if (k[1] > 0 && k[1] <= 0.5)
		k[1] = 0.3;
	if (k[1] > 0.3 && k[1] <= 0.7)
		k[1] = 0.3;
	if (k[1] > 0.5 && k[1] <= 1)
		k[1] = 0.9;
	return (k);
}

void			set_sepia_filter(t_col *col)
{
	int			tr;
	int			tg;
	int			tb;

	tr = (int)(0.393 * col->r + 0.769 * col->g + 0.189 * col->b);
	tg = (int)(0.349 * col->r + 0.686 * col->g + 0.168 * col->b);
	tb = (int)(0.272 * col->r + 0.534 * col->g + 0.131 * col->b);
	col->r = (unsigned char)fmin(tr, 255);
	col->g = (unsigned char)fmin(tg, 255);
	col->b = (unsigned char)fmin(tb, 255);
}

int				check_refr_coef(t_obj *obj)
{
	int			n;
	double		coef;
	int			i;

	n = 0;
	coef = 0.0;
	i = 1;
	while (++i < 15)
	{
		if (obj->refr <= coef)
		{
			n = i;
			return (n);
		}
		coef += 0.1;
	}
	return (n);
}

t_vect			get_reflect_ray(const t_vect *dirr, t_vect *normal)
{
	t_vect		reflect;

	reflect = vect_substr(*dirr, vect_multipl_const((*normal),
		2.0 * vect_multipl(*dirr, (*normal))));
	vect_normalise(&reflect);
	return (reflect);
}
