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

void				add_side_five(t_scene *scene, t_obj *base)
{
	t_vect			pos_fin;
	t_vect			dir;
	t_square		*square;
	t_obj			*side;

	square = (t_square *)base->data;
	pos_fin.x = square->position.x;
	pos_fin.y = square->position.y + (2 * square->k);
	pos_fin.z = square->position.z;
	dir.x = square->direction.x;
	dir.y = square->direction.y;
	dir.z = square->direction.z;
	side = new_square(ini_get_param_side(square->color, pos_fin, dir),
													square->k, 5, scene);
	((t_square *)side->data)->position_base = square->position;
	side->refl = base->refl;
	side->refr = base->refr;
	side->parent = base;
	add_obj_to_scene(scene, side);
}

void				add_side_four(t_scene *scene, t_obj *base)
{
	t_vect			pos_fin;
	t_vect			dir;
	t_square		*square;
	t_obj			*side;

	square = (t_square *)base->data;
	pos_fin.x = square->position.x;
	pos_fin.y = square->position.y + square->k;
	pos_fin.z = square->position.z - square->k;
	dir.x = 0;
	dir.y = 0;
	dir.z = square->direction.z - square->k;
	side = new_square(ini_get_param_side(square->color, pos_fin, dir),
													square->k, 4, scene);
	((t_square *)side->data)->position_base = square->position;
	side->refl = base->refl;
	side->refr = base->refr;
	side->parent = base;
	add_obj_to_scene(scene, side);
}

void				add_side_three(t_scene *scene, t_obj *base)
{
	t_vect			pos_fin;
	t_vect			dir;
	t_square		*square;
	t_obj			*side;

	square = (t_square *)base->data;
	pos_fin.x = square->position.x - square->k;
	pos_fin.y = square->position.y + square->k;
	pos_fin.z = square->position.z;
	dir.x = square->direction.x - square->k;
	dir.y = 0;
	dir.z = 0;
	side = new_square(ini_get_param_side(square->color, pos_fin, dir),
													square->k, 3, scene);
	((t_square *)side->data)->position_base = square->position;
	side->refl = base->refl;
	side->refr = base->refr;
	side->parent = base;
	add_obj_to_scene(scene, side);
}

void				add_side_two(t_scene *scene, t_obj *base)
{
	t_vect			pos_fin;
	t_vect			dir;
	t_square		*square;
	t_obj			*side;

	square = (t_square *)base->data;
	pos_fin.x = square->position.x;
	pos_fin.y = square->position.y + square->k;
	pos_fin.z = square->position.z + square->k;
	dir.x = 0;
	dir.y = 0;
	dir.z = square->direction.z + square->k;
	side = new_square(ini_get_param_side(square->color, pos_fin, dir),
													square->k, 2, scene);
	side->refl = base->refl;
	side->parent = base;
	side->refr = base->refr;
	((t_square *)side->data)->position_base =
								((t_square *)base->data)->position;
	add_obj_to_scene(scene, side);
}

void				add_side_one(t_scene *scene, t_obj *base)
{
	t_vect			pos_fin;
	t_vect			dir;
	t_square		*square;
	t_obj			*side;

	square = (t_square *)base->data;
	pos_fin.x = square->position.x + square->k;
	pos_fin.y = square->position.y + square->k;
	pos_fin.z = square->position.z;
	dir.x = square->direction.x + square->k;
	dir.y = 0;
	dir.z = 0;
	side = new_square(ini_get_param_side(square->color, pos_fin, dir),
												square->k, 1, scene);
	side->refl = base->refl;
	side->refr = base->refr;
	side->parent = base;
	((t_square *)side->data)->position_base =
									((t_square *)base->data)->position;
	add_obj_to_scene(scene, side);
}
