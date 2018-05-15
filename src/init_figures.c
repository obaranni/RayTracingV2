/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:36:08 by obaranni          #+#    #+#             */
/*   Updated: 2018/03/25 13:30:37 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define IFP ini_find_property
#define IPV ini_property_value

#include "../headers/rt.h"

void		sph_init(t_scene *scene, ini_t *ini, int section)
{
	t_obj	*obj;
	int		not_rot;

	obj = new_sphere(ini_get_pos(ini, section),
					ft_atoi(ini_get_prop(ini, section, "rad")),
					ini_get_col(ini, section),
					ini_get_cut(ini, section, &not_rot));
	obj->not_rotate = not_rot;
	obj->refl = ft_atof(ini_get_prop(ini, section, "refl"));
	obj->refr = ft_atof(ini_get_prop(ini, section, "refr"));
	add_obj_to_scene(scene, obj);
}

void		lig_init(t_scene *scene, ini_t *ini, int section)
{
	scene->lights = add_bid_lst(scene->lights,
								new_light(ini_get_param(ini, section),
								ini_get_secondary(ini, section)));
}

void		con_init(t_scene *scene, ini_t *ini, int section)
{
	t_obj	*obj;
	int		not_rot;

	obj = new_cone(ini_get_param(ini, section),
				ft_atof(ini_get_prop(ini, section, "ang")),
				ini_get_cut(ini, section, &not_rot));
	obj->not_rotate = not_rot;
	obj->refl = ft_atof(ini_get_prop(ini, section, "refl"));
	obj->refr = ft_atof(ini_get_prop(ini, section, "refr"));
	add_obj_to_scene(scene, obj);
}

void		cyl_init(t_scene *scene, ini_t *ini, int section)
{
	t_obj	*obj;
	int		not_rot;

	obj = new_cylinder(ini_get_param(ini, section),
					ft_atof(ini_get_prop(ini, section, "rad")),
					ini_get_cut(ini, section, &not_rot));
	obj->not_rotate = not_rot;
	obj->refl = ft_atof(ini_get_prop(ini, section, "refl"));
	obj->refr = ft_atof(ini_get_prop(ini, section, "refr"));
	add_obj_to_scene(scene, obj);
}

void		pln_init(t_scene *scene, ini_t *ini, int section)
{
	t_obj	*obj;
	int		not_rot;

	obj = new_plane(ini_get_pos(ini, section),
					ini_get_dir(ini, section),
					ini_get_col(ini, section),
					ini_get_cut(ini, section, &not_rot));
	obj->not_rotate = not_rot;
	obj->refl = ft_atof(ini_get_prop(ini, section, "refl"));
	obj->refr = ft_atof(ini_get_prop(ini, section, "refr"));
	obj->parent = NULL;
	add_obj_to_scene(scene, obj);
}
