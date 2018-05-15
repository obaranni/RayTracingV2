/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_eli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 00:30:29 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/15 00:31:56 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			eli_pos_backup(ini_t *ini, t_elips *eli, int sect_id)
{
	char		*str;

	str = ft_itoa((int)eli->position.x);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posX",
		(int)ft_strlen("posX")), str, 0);
	free(str);
	str = ft_itoa((int)eli->position.y);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posY",
		(int)ft_strlen("posY")), str, 0);
	free(str);
	str = ft_itoa((int)eli->position.z);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posZ",
		(int)ft_strlen("posZ")), str, 0);
	free(str);
}

void			eli_dir_backup(ini_t *ini, t_elips *eli, int sect_id)
{
	char		*str;

	str = ft_itoa((int)(eli->dir.x * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirX",
		(int)ft_strlen("dirX")), str, 0);
	free(str);
	str = ft_itoa((int)(eli->dir.y * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirY",
		(int)ft_strlen("dirY")), str, 0);
	free(str);
	str = ft_itoa((int)(eli->dir.z * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirZ",
		(int)ft_strlen("dirZ")), str, 0);
	free(str);
}

void			eli_col_backup(ini_t *ini, t_elips *eli, int sect_id)
{
	char		*str;

	str = ft_itoa((int)eli->color.r);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colR",
		(int)ft_strlen("colR")), str, 0);
	free(str);
	str = ft_itoa((int)eli->color.g);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colG",
		(int)ft_strlen("colG")), str, 0);
	free(str);
	str = ft_itoa((int)eli->color.b);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colB",
		(int)ft_strlen("colB")), str, 0);
	free(str);
}

int				eli_backup(ini_t *ini, t_obj *obj, int sect_id)
{
	t_elips	*eli;

	eli = (t_elips *)(obj->data);
	refr_refl_backup(ini, obj, sect_id);
	eli_pos_backup(ini, eli, sect_id);
	eli_dir_backup(ini, eli, sect_id);
	eli_col_backup(ini, eli, sect_id);
	return (0);
}
