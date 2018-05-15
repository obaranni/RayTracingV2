/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_get_funcs_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:25:33 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/03/05 17:45:26 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double			ini_get_refl_coef(ini_t *ini, int section)
{
	double		coef;
	int			prop;

	prop = ini_find_property(ini, section, "refl", 0);
	if (prop != -1)
	{
		coef = ft_atof(ini_property_value(ini, section, prop));
		if (coef < 1 && coef >= 0)
			return (coef);
	}
	return (1);
}

double			ini_get_refr_coef(ini_t *ini, int section)
{
	double		coef;
	int			prop;

	prop = ini_find_property(ini, section, "refr", 0);
	if (prop != -1)
	{
		coef = ft_atof(ini_property_value(ini, section, prop));
		if (coef < 1 && coef >= 0)
			return (coef);
	}
	return (1);
}

t_param			ini_get_param(ini_t *ini, int section)
{
	t_param param;

	param.dir = ini_get_dir(ini, section);
	param.col = ini_get_col(ini, section);
	param.pos = ini_get_pos(ini, section);
	return (param);
}

t_vect			ini_get_secondary(ini_t *ini, int section)
{
	t_vect		secondary;

	secondary = new_v(ft_atof(ini_get_prop(ini, section, "rad")),
					ft_atof(ini_get_prop(ini, section, "int")),
					ft_atof(ini_get_prop(ini, section, "type")));
	return (secondary);
}

t_param			ini_get_param_side(t_col col, t_vect pos, t_vect dir)
{
	t_param		param;

	param.dir = dir;
	param.col = col;
	param.pos = pos;
	return (param);
}
