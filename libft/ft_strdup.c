/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:18:56 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/03 19:40:31 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	i = -1;
	while (*(src + ++i))
		;
	dest = (char*)(malloc(sizeof(*src) * ++i));
	if (dest)
	{
		i = -1;
		while (*(src + ++i))
		{
			*(dest + i) = *(src + i);
		}
		*(dest + i) = '\0';
	}
	return (dest);
}
