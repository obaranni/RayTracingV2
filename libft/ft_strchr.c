/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:14:05 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/04 19:23:29 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (*(str + i) && (char)*(str + i) != (char)c)
		i++;
	if (*(str + i) == (char)c)
		return ((char *)(str + i));
	return (NULL);
}
