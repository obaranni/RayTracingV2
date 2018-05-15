/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_get_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:25:33 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/05/14 21:15:12 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

const char		*ini_get_prop(ini_t const *ini, int section, char const *name)
{
	int			prop;

	prop = ini_find_property(ini, section, name, (int)ft_strlen(name));
	if (prop == -1)
	{
		ft_putstr("In file: ");
		ft_putendl(ini->file_name);
		ft_putstr("Error ");
		ft_putstr(name);
		if (section == 0)
			ft_putendl(" property of global section.");
		else
		{
			ft_putstr(" property of object: ");
			ft_putendl(ini_section_name(ini, section));
		}
		exit(0);
	}
	return (ini_property_value(ini, section, prop));
}

t_cut			ini_get_cut(ini_t *ini, int section, int *not_rot)
{
	t_cut		cut;

	cut = new_cut(ft_atoi(ini_get_prop(ini, section, "type")),
					ft_atoi(ini_get_prop(ini, section, "axis")),
					ft_atof(ini_get_prop(ini, section, "cut_min")),
					ft_atof(ini_get_prop(ini, section, "cut_max")));
	*not_rot = !(cut.cut_max == 0 && cut.cut_min == 0);
	return (cut);
}

t_col			ini_get_col(ini_t *ini, int section)
{
	return (new_col((unsigned char)ft_atoi(ini_get_prop(ini, section, "colR")),
					(unsigned char)ft_atoi(ini_get_prop(ini, section, "colG")),
					(unsigned char)ft_atoi(ini_get_prop(ini, section, "colB")),
					0));
}

t_vect			ini_get_pos(ini_t *ini, int section)
{
	return (new_v(ft_atoi(ini_get_prop(ini, section, "posX")),
				ft_atoi(ini_get_prop(ini, section, "posY")),
				ft_atoi(ini_get_prop(ini, section, "posZ"))));
}

t_vect			ini_get_dir(ini_t *ini, int section)
{
	t_vect		res;

	res = new_v((double)ft_atoi(ini_get_prop(ini, section, "dirX")) / 1000000,
		(double)ft_atoi(ini_get_prop(ini, section, "dirY")) / 1000000,
		(double)ft_atoi(ini_get_prop(ini, section, "dirZ")) / 1000000);
	vect_normalise(&res);
	return (res);
}
