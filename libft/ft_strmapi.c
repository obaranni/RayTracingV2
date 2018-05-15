/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:09:54 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/05 23:14:58 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	i = -1;
	if (s)
	{
		if ((res = ft_strnew(ft_strlen(s))))
		{
			while (s && *(s + ++i))
				*(res + i) = f(i, *(s + i));
			if (i == ft_strlen(s))
				return (res);
			ft_strdel(&res);
		}
	}
	return (NULL);
}
