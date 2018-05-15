/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_properties.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:28:17 by obaranni          #+#    #+#             */
/*   Updated: 2018/02/27 14:56:26 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int				check_position(ini_t *ini, int section)
{
	if (ini_find_property(ini, section, "posX", 0) != -1 &&
		ini_find_property(ini, section, "posY", 0) != -1 &&
		ini_find_property(ini, section, "posZ", 0) != -1)
		return (0);
	ft_putstr("Error position property of object: ");
	if (!section)
		ft_putendl("camera");
	else
		ft_putendl(ini_section_name(ini, section));
	exit(0);
	return (0);
}

int				check_direction(ini_t *ini, int section)
{
	if (ini_find_property(ini, section, "dirX", 0) != -1 &&
		ini_find_property(ini, section, "dirY", 0) != -1 &&
		ini_find_property(ini, section, "dirZ", 0) != -1)
		return (0);
	ft_putstr("Error direction property of object: ");
	ft_putendl(ini_section_name(ini, section));
	exit(0);
	return (0);
}

int				check_color(ini_t *ini, int section)
{
	if (ini_find_property(ini, section, "colR", 0) != -1 &&
		ini_find_property(ini, section, "colG", 0) != -1 &&
		ini_find_property(ini, section, "colB", 0) != -1)
		return (0);
	ft_putstr("Error color property of object: ");
	ft_putendl(ini_section_name(ini, section));
	exit(0);
	return (0);
}

int				check_position_pol(ini_t *ini, int section)
{
	if (ini_find_property(ini, section, "pos_aX", 0) != -1 &&
		ini_find_property(ini, section, "pos_aY", 0) != -1 &&
		ini_find_property(ini, section, "pos_aZ", 0) != -1)
		return (0);
	if (ini_find_property(ini, section, "pos_bX", 0) != -1 &&
		ini_find_property(ini, section, "pos_bY", 0) != -1 &&
		ini_find_property(ini, section, "pos_bZ", 0) != -1)
		return (0);
	if (ini_find_property(ini, section, "pos_cX", 0) != -1 &&
		ini_find_property(ini, section, "pos_cY", 0) != -1 &&
		ini_find_property(ini, section, "pos_cZ", 0) != -1)
		return (0);
	ft_putstr("Error position property of object: ");
	if (!section)
		ft_putendl("camera");
	else
		ft_putendl(ini_section_name(ini, section));
	exit(0);
	return (0);
}

int				check_cut(ini_t *ini, int section)
{
	if (ini_find_property(ini, section, "type", 0) != -1 &&
		ini_find_property(ini, section, "axis", 0) != -1 &&
		ini_find_property(ini, section, "cut_min", 0) != -1 &&
		ini_find_property(ini, section, "cut_max", 0) != -1)
		return (0);
	ft_putstr("Error cut property of object: ");
	ft_putendl(ini_section_name(ini, section));
	exit(0);
	return (0);
}
