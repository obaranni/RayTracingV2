/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_dis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 00:32:28 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/15 00:33:30 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			dis_pos_backup(ini_t *ini, t_disc *dis, int sect_id)
{
	char		*str;

	str = ft_itoa((int)dis->position.x);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posX",
		(int)ft_strlen("posX")), str, 0);
	free(str);
	str = ft_itoa((int)dis->position.y);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posY",
		(int)ft_strlen("posY")), str, 0);
	free(str);
	str = ft_itoa((int)dis->position.z);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posZ",
		(int)ft_strlen("posZ")), str, 0);
	free(str);
}

void			dis_dir_backup(ini_t *ini, t_disc *dis, int sect_id)
{
	char		*str;

	str = ft_itoa((int)(dis->direction.x * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirX",
		(int)ft_strlen("dirX")), str, 0);
	free(str);
	str = ft_itoa((int)(dis->direction.y * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirY",
		(int)ft_strlen("dirY")), str, 0);
	free(str);
	str = ft_itoa((int)(dis->direction.z * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirZ",
		(int)ft_strlen("dirZ")), str, 0);
	free(str);
}

void			dis_col_backup(ini_t *ini, t_disc *dis, int sect_id)
{
	char		*str;

	str = ft_itoa((int)dis->color.r);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colR",
		(int)ft_strlen("colR")), str, 0);
	free(str);
	str = ft_itoa((int)dis->color.g);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colG",
		(int)ft_strlen("colG")), str, 0);
	free(str);
	str = ft_itoa((int)dis->color.b);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colB",
		(int)ft_strlen("colB")), str, 0);
	free(str);
}

int				dis_backup(ini_t *ini, t_obj *obj, int sect_id)
{
	t_disc	*dis;

	dis = (t_disc *)(obj->data);
	refr_refl_backup(ini, obj, sect_id);
	dis_pos_backup(ini, dis, sect_id);
	dis_dir_backup(ini, dis, sect_id);
	dis_col_backup(ini, dis, sect_id);
	return (0);
}
