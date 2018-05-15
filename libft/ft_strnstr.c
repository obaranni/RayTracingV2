/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:57:54 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/12 21:55:53 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*n;
	size_t	i;
	size_t	j;
	size_t	k;

	k = -1;
	if (!(char)*to_find)
		return ((char *)str);
	while (*(str + ++k) && k < len)
	{
		i = 0;
		j = 0;
		while (*(str + k + i) && *(str + k + i) != *to_find && k + i < len)
			i++;
		if (*(str + k + i) == *to_find && k + i < len)
			n = (char *)(str + k + i);
		while (*(str + k + i) == *(to_find + j) && k + i < len)
		{
			if (*(str + k + i) && *(to_find + j++) && k + i < len)
				i++;
			if (!*(to_find + j))
				return (n);
		}
	}
	return (NULL);
}
