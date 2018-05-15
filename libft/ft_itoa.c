/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:14:00 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/09 23:04:18 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_capacity(int n)
{
	long	buf;
	size_t	l;

	buf = (long)n;
	l = 1;
	if (buf < 0)
	{
		l++;
		buf *= -1;
	}
	while (buf > 9)
	{
		buf /= 10;
		l++;
	}
	return (l);
}

char			*ft_itoa(int n)
{
	char	*res;
	size_t	l;
	long	buf;

	buf = (long)n;
	if (buf < 0)
		buf *= -1;
	l = ft_int_capacity(n);
	if ((res = ft_strnew(l)))
	{
		while (l-- > 0)
		{
			*(res + l) = buf % 10 + 48;
			buf /= 10;
		}
		if (n < 0)
			*res = '-';
	}
	return (res);
}
