/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 23:08:58 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/02/27 13:58:15 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int					ft_rgb_to_int(unsigned char r,
									unsigned char g,
									unsigned char b)
{
	return ((b + g * 256 + r * 65536));
}

int					get_refl_color(int mirr_col, int obj_col, double refl_coef)
{
	double			refl_obj;

	refl_obj = 1 - refl_coef;
	return (ft_rgb_to_int((unsigned char)((mirr_col / 256 / 256 % 256)
										* refl_coef
							+ (obj_col / 256 / 256 % 256) * refl_obj),
			(unsigned char)(((mirr_col / 256) % 256) * refl_coef
							+ ((obj_col / 256) % 256) * refl_obj),
			(unsigned char)((mirr_col % 256) * refl_coef
							+ (obj_col % 256) * refl_obj)));
}

t_col				new_col(unsigned char r, unsigned char g,
							unsigned char b, unsigned char a)
{
	t_col			res;

	res.r = r;
	res.g = g;
	res.b = b;
	res.a = a;
	return (res);
}
