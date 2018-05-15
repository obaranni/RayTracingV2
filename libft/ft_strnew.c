/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:38:23 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/27 23:02:52 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	if ((res = (char *)malloc(size + 1)))
	{
		size += 1;
		while (size > 0)
			*(res + size-- - 1) = '\0';
		return (res);
	}
	return (NULL);
}
