/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:53:31 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/03 19:34:14 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (*(dest + i) != '\0')
		i++;
	while (*(src + j) != '\0')
		*(dest + i++) = *(src + j++);
	*(dest + i) = '\0';
	return (dest);
}
