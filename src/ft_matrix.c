/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 23:00:40 by ymitelsk          #+#    #+#             */
/*   Updated: 2017/09/16 23:00:42 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

double					***ft_mulltipl_matr(double ***m1, double ***m2,
											double ***res)
{
	int					i;
	int					j;
	int					k;
	double				***buf;

	i = -1;
	buf = ft_create_matrix(4, 4, 0);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				*(*(*(buf + i) + j)) +=
						*(*(*(m1 + i) + k)) * *(*(*(m2 + k) + j));
		}
	}
	if (res)
		ft_destroy_matrix(res);
	return (buf);
}

void					ft_destroy_matrix(double ***m)
{
	int					i;
	int					j;

	i = 0;
	while (*(m + i))
	{
		j = 0;
		while (*(*(m + i) + j))
		{
			free(*(*(m + i) + j));
			j++;
		}
		free(*(m + i));
		i++;
	}
	free(m);
}

double					***ft_create_matrix(int i, int j, int dv)
{
	double				***mat;
	int					n;

	n = j;
	mat = (double ***)ft_memalloc(sizeof(mat) * (i + 1));
	*(mat + i) = 0;
	while (i-- > 0)
	{
		j = n;
		*(mat + i) = (double **)ft_memalloc(sizeof(*mat) * (j + 1));
		*(*(mat + i) + j) = 0;
		while (j-- > 0)
		{
			*(*(mat + i) + j) = (double *)ft_memalloc(sizeof(**mat));
			*(*(*(mat + i) + j)) = (i == j ? dv : 0);
		}
	}
	return (mat);
}
