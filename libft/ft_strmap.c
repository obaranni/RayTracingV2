/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:36:45 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/05 23:09:47 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	i = -1;
	if (s)
	{
		if ((res = ft_strnew(ft_strlen(s))))
		{
			while (s && *(s + ++i))
				*(res + i) = f(*(s + i));
			if (i == ft_strlen(s))
				return (res);
			ft_strdel(&res);
		}
	}
	return (NULL);
}
