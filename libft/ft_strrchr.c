/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:14:05 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/04 19:35:36 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*n;
	size_t	i;

	i = 0;
	n = NULL;
	while (*(str + i))
	{
		if (*(str + i) == (char)c)
			n = ((char *)(str + i));
		i++;
	}
	if (*(str + i) == (char)c)
		n = ((char *)(str + i));
	return (n);
}
