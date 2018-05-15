/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:56:34 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/05/13 20:56:43 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_vect			get_vect(const t_vect *vect, double ***const *matr, t_vect *buf)
{
	(*buf).x = vect->x * *matr[0][0][0] + vect->y * *matr[0][1][0]
				+ vect->z * *matr[0][2][0] + 1 * *matr[0][3][0];
	(*buf).y = vect->x * *matr[0][0][1] + vect->y * *matr[0][1][1]
				+ vect->z * *matr[0][2][1] + 1 * *matr[0][3][1];
	(*buf).z = vect->x * *matr[0][0][2] + vect->y * *matr[0][1][2]
				+ vect->z * *matr[0][2][2] + 1 * *matr[0][3][2];
	return (*buf);
}

void			rotate(t_vect *vect, t_vect angels)
{
	double		***matr[6];
	int			i;
	t_vect		buf;

	matr[0] = ft_create_matrix(4, 4, 1);
	matr[1] = ft_rotate_x(angels.x);
	matr[2] = ft_rotate_y(angels.y);
	matr[3] = ft_rotate_z(angels.z);
	if (angels.x != 0)
		matr[0] = ft_mulltipl_matr(matr[1], matr[0], matr[0]);
	if (angels.y != 0)
		matr[0] = ft_mulltipl_matr(matr[2], matr[0], matr[0]);
	if (angels.z != 0)
		matr[0] = ft_mulltipl_matr(matr[3], matr[0], matr[0]);
	buf = get_vect(vect, matr, &buf);
	vect->x = buf.x;
	vect->y = buf.y;
	vect->z = buf.z;
	i = 4;
	while (i-- > 0)
		ft_destroy_matrix(matr[i]);
}

int				rotations(GtkWidget *widget, GdkEventKey *event, t_scene *scene)
{
	t_vect		shift;

	(void)widget;
	shift = new_v(0, 0, 0);
	if (scene->env->current && !scene->env->current->obj->not_rotate)
	{
		shift.x += event->keyval == GDK_KEY_W ? 10 : 0;
		shift.x -= event->keyval == GDK_KEY_S ? 10 : 0;
		shift.y += event->keyval == GDK_KEY_D ? 10 : 0;
		shift.y -= event->keyval == GDK_KEY_A ? 10 : 0;
		shift.z += event->keyval == GDK_KEY_E ? 10 : 0;
		shift.z -= event->keyval == GDK_KEY_Q ? 10 : 0;
		if ((shift.x + shift.y + shift.z) != 0)
		{
			rotate(&scene->env->current->direction, shift);
			return (1);
		}
	}
	return (0);
}

int				qual_hooks(GtkWidget *widget,
							GdkEventKey *event, t_scene *scene)
{
	(void)widget;
	if (event->keyval == GDK_KEY_bracketleft && scene->qual < 74)
	{
		scene->qual *= 2;
		return (1);
	}
	else if (event->keyval == GDK_KEY_bracketright && scene->qual > 0.2)
	{
		scene->qual /= 2;
		return (1);
	}
	return (0);
}
