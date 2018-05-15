/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:29:40 by obaranni          #+#    #+#             */
/*   Updated: 2018/05/15 17:44:42 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

void				chouse_obj(ini_t *ini, t_obj *obj, int i)
{
	if ((int)obj->type == 0)
		pln_backup(ini, obj, i);
	else if ((int)obj->type == 1)
		sph_backup(ini, obj, i);
	else if ((int)obj->type == 2)
		cyl_backup(ini, obj, i);
	else if ((int)obj->type == 3)
		con_backup(ini, obj, i);
	else if ((int)obj->type == 5)
		dis_backup(ini, obj, i);
	else if ((int)obj->type == 6)
		eli_backup(ini, obj, i);
	else if ((int)obj->type == 7)
		par_backup(ini, obj, i);
	else if ((int)obj->type == 8)
		squ_backup(ini, obj, i);
}

void				backup_objs(ini_t *ini, t_bid_list *tmp_elem, int i)
{
	t_obj			*obj;

	while (tmp_elem)
	{
		obj = ((t_obj *)(tmp_elem->data));
		while (ini_section_name(ini, i) &&
				!ft_strcmp(ini_section_name(ini, i), "lig"))
			i++;
		while (tmp_elem && (int)obj->type == 8 && ((t_square
				*)(obj->data))->side != 0)
		{
			tmp_elem = tmp_elem->next;
			i++;
		}
		if (tmp_elem)
		{
			chouse_obj(ini, obj, i);
			tmp_elem = tmp_elem->next;
		}
		i++;
	}
}

int					cam_backup(ini_t *ini, struct s_camera cam)
{
	char			*position;

	position = ft_itoa((int)cam.position.x);
	ini_property_value_set(ini, 0, ini_find_property(ini, 0, "posX",
		(int)ft_strlen("posX")), position, 0);
	free(position);
	position = ft_itoa((int)cam.position.y);
	ini_property_value_set(ini, 0, ini_find_property(ini, 0, "posY",
		(int)ft_strlen("posY")), position, 0);
	free(position);
	position = ft_itoa((int)cam.position.z);
	ini_property_value_set(ini, 0, ini_find_property(ini, 0, "posZ",
		(int)ft_strlen("posZ")), position, 0);
	free(position);
	return (0);
}

int					backup_scene_params(ini_t *ini, t_scene *scene)
{
	char			*param;

	param = ft_itoa(scene->sepia_flag);
	ini_property_value_set(ini, 0, ini_find_property(ini, 0, "sepia",
		(int)ft_strlen("sepia")), param, 0);
	free(param);
	param = ft_itoa(scene->cartoon_flag);
	ini_property_value_set(ini, 0, ini_find_property(ini, 0, "cartoon",
		(int)ft_strlen("cartoon")), param, 0);
	free(param);
	param = ft_itoa(scene->specularity);
	ini_property_value_set(ini, 0, ini_find_property(ini, 0, "specularity",
		(int)ft_strlen("specularity")), param, 0);
	free(param);
	return (0);
}

int					backup(t_env *env)
{
	ini_t			*ini_tmp;

	ini_tmp = ini_load(env->scene->backup.buf, 0);
	cam_backup(ini_tmp, ((env->scene))->cam);
	backup_scene_params(ini_tmp, env->scene);
	backup_objs(ini_tmp, ((env->scene)->objs), 1);
	create_file(ini_tmp, env);
	env->scene->backup.count++;
	return (0);
}
