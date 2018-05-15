/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:24:55 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/10/30 03:24:58 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double				check_square_cut_help(double t1, const t_vect *start_pnt,
					const t_vect *vect, void *data)
{
	double			x;
	double			z;
	const t_square	*square;

	square = (t_square *)data;
	if (square->side == 1 || square->side == 3)
	{
		x = start_pnt->y + t1 * vect->y;
		z = start_pnt->z + t1 * vect->z;
		if (x > (square->position.y - square->k) && x < square->k +
			square->position.y && z > (square->position.z - square->k)
			&& z < square->k + square->position.z)
			return (t1);
	}
	if (square->side == 2 || square->side == 4)
	{
		x = start_pnt->x + t1 * vect->x;
		z = start_pnt->y + t1 * vect->y;
		if (x > (square->position.x - square->k) && x < square->k
			+ square->position.x && z > (square->position.y - square->k)
			&& z < square->k + square->position.y)
			return (t1);
	}
	return (0);
}

double				check_square_cut(double t1, const t_vect *start_pnt,
					const t_vect *vect, void *data)
{
	double			x;
	double			z;
	const t_square	*square;

	square = (t_square *)data;
	if (square->k == 0)
		return (t1);
	if (square->side == 0 || square->side == 5)
	{
		x = start_pnt->x + t1 * vect->x;
		z = start_pnt->z + t1 * vect->z;
		if (x > (square->position.x - square->k) && x < square->k +
			square->position.x && z > (square->position.z - square->k)
			&& z < square->k + square->position.z)
			return (t1);
	}
	return (check_square_cut_help(t1, start_pnt, vect, data));
}

void				check_refr_pos(t_square *square, t_obj *obj)
{
	t_square	*sq;

	sq = (t_square *)obj->data;
	if (square->side == 1)
	{
		square->position.x = ((t_square*)obj->parent->data)->position.x
		+ square->k;
		square->position.y = ((t_square*)obj->parent->data)->position.y
		+ square->k;
		square->position.z = ((t_square*)obj->parent->data)->position.z;
	}
	if (square->side == 2)
	{
		square->position.x = ((t_square*)obj->parent->data)->position.x;
		square->position.y = ((t_square*)obj->parent->data)->position.y
		+ square->k;
		square->position.z = ((t_square*)obj->parent->data)->position.z
		+ square->k;
	}
	if (square->side != 0)
	{
		sq->color = ((t_square *)obj->parent->data)->color;
		obj->refl = obj->parent->refl;
		obj->refr = obj->parent->refr;
	}
}

void				change_side_pos(t_square *square, t_obj *obj)
{
	if (square->side == 3)
	{
		square->position.x = ((t_square*)obj->parent->data)->position.x
		- square->k;
		square->position.y = ((t_square*)obj->parent->data)->position.y
		+ square->k;
		square->position.z = ((t_square*)obj->parent->data)->position.z;
	}
	if (square->side == 4)
	{
		square->position.x = ((t_square*)obj->parent->data)->position.x;
		square->position.y = ((t_square*)obj->parent->data)->position.y
		+ square->k;
		square->position.z = ((t_square*)obj->parent->data)->position.z
		- square->k;
	}
	if (square->side == 5)
	{
		square->position.x = ((t_square*)obj->parent->data)->position.x;
		square->position.y = ((t_square*)obj->parent->data)->position.y
		+ (2 * square->k);
		square->position.z = ((t_square*)obj->parent->data)->position.z;
	}
}
