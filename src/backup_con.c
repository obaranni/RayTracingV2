/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_con.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:11:48 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/14 21:12:00 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			con_pos_backup(ini_t *ini, t_cone *con, int sect_id)
{
	char		*str;

	str = ft_itoa((int)con->position.x);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posX",
		(int)ft_strlen("posX")), str, 0);
	free(str);
	str = ft_itoa((int)con->position.y);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posY",
		(int)ft_strlen("posY")), str, 0);
	free(str);
	str = ft_itoa((int)con->position.z);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posZ",
		(int)ft_strlen("posZ")), str, 0);
	free(str);
}

void			con_dir_backup(ini_t *ini, t_cone *con, int sect_id)
{
	char		*str;

	str = ft_itoa((int)(con->direction.x * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirX",
		(int)ft_strlen("dirX")), str, 0);
	free(str);
	str = ft_itoa((int)(con->direction.y * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirY",
		(int)ft_strlen("dirY")), str, 0);
	free(str);
	str = ft_itoa((int)(con->direction.z * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirZ",
		(int)ft_strlen("dirZ")), str, 0);
	free(str);
}

void			con_col_backup(ini_t *ini, t_cone *con, int sect_id)
{
	char		*str;

	str = ft_itoa((int)con->color.r);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colR",
		(int)ft_strlen("colR")), str, 0);
	free(str);
	str = ft_itoa((int)con->color.g);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colG",
		(int)ft_strlen("colG")), str, 0);
	free(str);
	str = ft_itoa((int)con->color.b);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colB",
		(int)ft_strlen("colB")), str, 0);
	free(str);
}

int				con_backup(ini_t *ini, t_obj *obj, int sect_id)
{
	t_cone	*con;

	con = (t_cone *)(obj->data);
	refr_refl_backup(ini, obj, sect_id);
	con_pos_backup(ini, con, sect_id);
	con_dir_backup(ini, con, sect_id);
	con_col_backup(ini, con, sect_id);
	return (0);
}
