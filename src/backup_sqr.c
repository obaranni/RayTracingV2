/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_sqr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 00:30:05 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/15 00:30:18 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			squ_pos_backup(ini_t *ini, t_square *squ, int sect_id)
{
	char		*str;

	str = ft_itoa((int)squ->position.x);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posX",
		(int)ft_strlen("posX")), str, 0);
	free(str);
	str = ft_itoa((int)squ->position.y);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posY",
		(int)ft_strlen("posY")), str, 0);
	free(str);
	str = ft_itoa((int)squ->position.z);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posZ",
		(int)ft_strlen("posZ")), str, 0);
	free(str);
}

void			squ_col_backup(ini_t *ini, t_square *squ, int sect_id)
{
	char		*str;

	str = ft_itoa((int)squ->color.r);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colR",
		(int)ft_strlen("colR")), str, 0);
	free(str);
	str = ft_itoa((int)squ->color.g);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colG",
		(int)ft_strlen("colG")), str, 0);
	free(str);
	str = ft_itoa((int)squ->color.b);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colB",
		(int)ft_strlen("colB")), str, 0);
	free(str);
}

int				squ_backup(ini_t *ini, t_obj *obj, int sect_id)
{
	t_square	*squ;

	squ = (t_square *)(obj->data);
	refr_refl_backup(ini, obj, sect_id);
	squ_pos_backup(ini, squ, sect_id);
	squ_col_backup(ini, squ, sect_id);
	return (0);
}
