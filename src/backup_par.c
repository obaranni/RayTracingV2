/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_par.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 00:33:41 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/15 00:34:23 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void			par_pos_backup(ini_t *ini, t_parab *par, int sect_id)
{
	char		*str;

	str = ft_itoa((int)par->position.x);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posX",
		(int)ft_strlen("posX")), str, 0);
	free(str);
	str = ft_itoa((int)par->position.y);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posY",
		(int)ft_strlen("posY")), str, 0);
	free(str);
	str = ft_itoa((int)par->position.z);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "posZ",
		(int)ft_strlen("posZ")), str, 0);
	free(str);
}

void			par_dir_backup(ini_t *ini, t_parab *par, int sect_id)
{
	char		*str;

	str = ft_itoa((int)(par->direction.x * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirX",
		(int)ft_strlen("dirX")), str, 0);
	free(str);
	str = ft_itoa((int)(par->direction.y * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirY",
		(int)ft_strlen("dirY")), str, 0);
	free(str);
	str = ft_itoa((int)(par->direction.z * 1000000));
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "dirZ",
		(int)ft_strlen("dirZ")), str, 0);
	free(str);
}

void			par_col_backup(ini_t *ini, t_parab *par, int sect_id)
{
	char		*str;

	str = ft_itoa((int)par->color.r);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colR",
		(int)ft_strlen("colR")), str, 0);
	free(str);
	str = ft_itoa((int)par->color.g);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colG",
		(int)ft_strlen("colG")), str, 0);
	free(str);
	str = ft_itoa((int)par->color.b);
	ini_property_value_set(ini, sect_id, ini_find_property(ini, sect_id, "colB",
		(int)ft_strlen("colB")), str, 0);
	free(str);
}

int				par_backup(ini_t *ini, t_obj *obj, int sect_id)
{
	t_parab	*par;

	par = (t_parab *)(obj->data);
	refr_refl_backup(ini, obj, sect_id);
	par_pos_backup(ini, par, sect_id);
	par_dir_backup(ini, par, sect_id);
	par_col_backup(ini, par, sect_id);
	return (0);
}
