/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:54:32 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/04 20:58:21 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (*(dest + ++i))
		;
	while (*(src + ++j) && j < nb)
		*(dest + i + j) = *(src + j);
	*(dest + i + j) = '\0';
	return (dest);
}
