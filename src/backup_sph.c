/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_sph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:09:06 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/14 21:09:25 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			sph_pos_backup(ini_t *ini, t_sphere *sph, int sect_id)
{
	char		*str;

	str = ft_itoa((int)sph->position.x);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posX",
	(int)ft_strlen("posX")), str, 0);
	free(str);
	str = ft_itoa((int)sph->position.y);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posY",
	(int)ft_strlen("posY")), str, 0);
	free(str);
	str = ft_itoa((int)sph->position.z);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posZ",
		(int)ft_strlen("posZ")), str, 0);
	free(str);
}

void			sph_col_backup(ini_t *ini, t_sphere *sph, int sect_id)
{
	char		*str;

	str = ft_itoa((int)sph->color.r);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colR",
		(int)ft_strlen("colR")), str, 0);
	free(str);
	str = ft_itoa((int)sph->color.g);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colG",
		(int)ft_strlen("colG")), str, 0);
	free(str);
	str = ft_itoa((int)sph->color.b);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colB",
		(int)ft_strlen("colB")), str, 0);
	free(str);
}

int				sph_backup(ini_t *ini, t_obj *obj, int sect_id)
{
	t_sphere	*sph;

	sph = (t_sphere *)(obj->data);
	refr_refl_backup(ini, obj, sect_id);
	sph_pos_backup(ini, sph, sect_id);
	sph_col_backup(ini, sph, sect_id);
	return (0);
}
