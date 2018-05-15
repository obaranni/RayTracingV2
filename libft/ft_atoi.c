/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 21:15:45 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/14 21:21:00 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t				i;
	unsigned long int	res;
	int					f;

	i = 0;
	res = 0;
	f = 1;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	if (*(str + i) == 45)
		f = -1;
	if (*(str + i) == 43 || *(str + i) == 45)
		i++;
	while (*(str + i) >= 48 && *(str + i) <= 57)
	{
		res = res * 10 + (*(str + i) - '0');
		if (res >= 9223372036854775807 && f == 1)
			return (-1);
		if (res > 9223372036854775807 && f == -1)
			return (0);
		i++;
	}
	return ((int)(res * f));
}
