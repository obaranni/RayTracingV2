/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:31:34 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/10 21:32:55 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*n;
	size_t	i;
	size_t	j;
	size_t	k;

	k = -1;
	if (!(char)*to_find)
		return ((char *)str);
	while (*(str + ++k))
	{
		i = 0;
		j = 0;
		while (*(str + k + i) && *(str + k + i) != *to_find)
			i++;
		if (*(str + k + i) == *to_find)
			n = (char *)(str + k + i);
		while (*(str + k + i) == *(to_find + j))
		{
			if (*(str + k + i++) != '\0' && *(to_find + j) != '\0')
				j++;
			if (!*(to_find + j))
				return (n);
		}
	}
	return (NULL);
}
