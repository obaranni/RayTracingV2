/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:09:57 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/14 21:10:23 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			pln_pos_backup(ini_t *ini, t_plane *pln, int sect_id)
{
	char		*str;

	str = ft_itoa((int)pln->position.x);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posX",
		(int)ft_strlen("posX")), str, 0);
	free(str);
	str = ft_itoa((int)pln->position.y);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posY",
		(int)ft_strlen("posY")), str, 0);
	free(str);
	str = ft_itoa((int)pln->position.z);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posZ",
		(int)ft_strlen("posZ")), str, 0);
	free(str);
}

void			pln_dir_backup(ini_t *ini, t_plane *pln, int sect_id)
{
	char		*str;

	str = ft_itoa((int)(pln->direction.x * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirX",
	(int)ft_strlen("dirX")), str, 0);
	free(str);
	str = ft_itoa((int)(pln->direction.y * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirY",
	(int)ft_strlen("dirY")), str, 0);
	free(str);
	str = ft_itoa((int)(pln->direction.z * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirZ",
	(int)ft_strlen("dirZ")), str, 0);
	free(str);
}

void			pln_col_backup(ini_t *ini, t_plane *pln, int sect_id)
{
	char		*str;

	str = ft_itoa((int)pln->color.r);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colR",
		(int)ft_strlen("colR")), str, 0);
	free(str);
	str = ft_itoa((int)pln->color.g);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colG",
		(int)ft_strlen("colG")), str, 0);
	free(str);
	str = ft_itoa((int)pln->color.b);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colB",
		(int)ft_strlen("colB")), str, 0);
	free(str);
}

int				pln_backup(ini_t *ini, t_obj *obj, int sect_id)
{
	t_plane	*pln;

	pln = (t_plane *)(obj->data);
	refr_refl_backup(ini, obj, sect_id);
	pln_pos_backup(ini, pln, sect_id);
	pln_dir_backup(ini, pln, sect_id);
	pln_col_backup(ini, pln, sect_id);
	return (0);
}
