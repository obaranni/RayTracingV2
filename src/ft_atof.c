/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 09:12:49 by obaranni          #+#    #+#             */
/*   Updated: 2018/03/19 09:13:43 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int			count_zeros(char **box)
{
	int		i;

	i = 0;
	while (**box == '0')
	{
		i++;
		(*box)++;
	}
	return (i);
}

double		ft_atof(const char *str)
{
	double	res;
	char	*box;
	int		dig;

	box = (char *)str;
	res = 0;
	dig = 0;
	while (ft_isdigit(*box))
	{
		dig++;
		box++;
	}
	if (*box == '.')
	{
		box++;
		res += (double)ft_atoi(box) / pow((double)10,
			(double)(count_zeros(&box) + ft_strlen(box)));
	}
	res += ft_atoi(str);
	return (res);
}
