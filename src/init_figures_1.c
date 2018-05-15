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

#include "../headers/rt.h"

void		dis_init(t_scene *scene, ini_t *ini, int section)
{
	t_obj	*obj;

	obj = new_disc(ini_get_pos(ini, section),
				ini_get_dir(ini, section),
				ini_get_col(ini, section),
				ft_atof(ini_get_prop(ini, section, "rad")));
	obj->refl = ft_atof(ini_get_prop(ini, section, "refl"));
	obj->refr = ft_atof(ini_get_prop(ini, section, "refr"));
	obj->parent = NULL;
	obj->not_rotate = 0;
	add_obj_to_scene(scene, obj);
}

void		pol_init(t_scene *scene, ini_t *ini, int section)
{
	t_obj	*obj;

	obj = new_pol(new_v(ft_atoi(ini_get_prop(ini, section, "pos_aX")),
						ft_atoi(ini_get_prop(ini, section, "pos_aY")),
						ft_atoi(ini_get_prop(ini, section, "pos_aZ"))),
				new_v(ft_atoi(ini_get_prop(ini, section, "pos_bX")),
						ft_atoi(ini_get_prop(ini, section, "pos_bY")),
						ft_atoi(ini_get_prop(ini, section, "pos_bZ"))),
				new_v(ft_atoi(ini_get_prop(ini, section, "pos_cX")),
						ft_atoi(ini_get_prop(ini, section, "pos_cY")),
						ft_atoi(ini_get_prop(ini, section, "pos_cZ"))),
				ini_get_col(ini, section));
	obj->refl = ft_atof(ini_get_prop(ini, section, "refl"));
	obj->refr = ft_atof(ini_get_prop(ini, section, "refr"));
	obj->parent = NULL;
	obj->not_rotate = 1;
	add_obj_to_scene(scene, obj);
}

void		par_init(t_scene *scene, ini_t *ini, int section)
{
	t_obj	*obj;
	int		not_rot;

	obj = new_parab(ini_get_param(ini, section),
					ft_atof(ini_get_prop(ini, section, "rad")),
					ini_get_cut(ini, section, &not_rot));
	obj->not_rotate = not_rot;
	obj->parent = NULL;
	obj->refl = ft_atof(ini_get_prop(ini, section, "refl"));
	obj->refr = ft_atof(ini_get_prop(ini, section, "refr"));
	add_obj_to_scene(scene, obj);
}

void		sqr_init(t_scene *scene, ini_t *ini, int section)
{
	t_obj	*square;

	square = new_square(ini_get_param(ini, section),
						ft_atof(ini_get_prop(ini, section, "k")), 0, scene);
	square->refl = ini_get_refl_coef(ini, section);
	square->parent = NULL;
	square->not_rotate = 1;
	square->refl = ft_atof(ini_get_prop(ini, section, "refl"));
	square->refr = ft_atof(ini_get_prop(ini, section, "refr"));
	scene->sq_b = (t_square*)square->data;
	scene->sq_b->direction = new_v(0, 1, 0);
	add_obj_to_scene(scene, square);
	add_side_one(scene, square);
	add_side_two(scene, square);
	add_side_three(scene, square);
	add_side_four(scene, square);
	add_side_five(scene, square);
}

void		eli_init(t_scene *scene, ini_t *ini, int section)
{
	t_obj	*obj;
	int		not_rot;

	obj = new_elips(ini_get_param(ini, section),
					ft_atof(ini_get_prop(ini, section, "rad")),
					ft_atof(ini_get_prop(ini, section, "dist")),
					ini_get_cut(ini, section, &not_rot));
	obj->not_rotate = not_rot;
	obj->refl = ft_atof(ini_get_prop(ini, section, "refl"));
	obj->refr = ft_atof(ini_get_prop(ini, section, "refr"));
	obj->parent = NULL;
	add_obj_to_scene(scene, obj);
}
