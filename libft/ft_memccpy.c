/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:20:51 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/02 21:58:25 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *out, const void *in, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*src;

	res = (unsigned char *)out;
	src = (unsigned char *)in;
	i = 0;
	while (i < n)
	{
		*(res + i) = *(src + i);
		if (*(res + i) == (unsigned char)c)
			return (res + i + 1);
		i++;
	}
	return (NULL);
}
