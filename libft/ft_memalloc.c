/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:06:27 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/28 22:37:23 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;

	if ((res = malloc(size)))
	{
		while (size > 0)
			*(res + --size) = 0;
		return (res);
	}
	return (NULL);
}
