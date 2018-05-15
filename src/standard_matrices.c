/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 23:08:12 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/09/16 23:08:13 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double			***ft_rotate_x(double f_gr)
{
	double		f_rad;
	double		***mat;

	f_rad = (M_PI / 180) * f_gr;
	mat = ft_create_matrix(4, 4, 1);
	*mat[1][1] = cos(f_rad);
	*mat[1][2] = sin(f_rad);
	*mat[2][1] = -(*mat[1][2]);
	*mat[2][2] = *mat[1][1];
	return (mat);
}

double			***ft_rotate_y(double f_gr)
{
	double		f_rad;
	double		***mat;

	f_rad = (M_PI / 180) * f_gr;
	mat = ft_create_matrix(4, 4, 1);
	*mat[0][0] = cos(f_rad);
	*mat[0][2] = -sin(f_rad);
	*mat[2][0] = -(*mat[0][2]);
	*mat[2][2] = *mat[0][0];
	return (mat);
}

double			***ft_rotate_z(double f_gr)
{
	double		f_rad;
	double		***mat;

	f_rad = (M_PI / 180) * f_gr;
	mat = ft_create_matrix(4, 4, 1);
	*mat[0][0] = cos(f_rad);
	*mat[0][1] = sin(f_rad);
	*mat[1][0] = -(*mat[0][1]);
	*mat[1][1] = *mat[0][0];
	return (mat);
}
