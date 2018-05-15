/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 22:28:55 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/20 22:46:01 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strstr_count(const char *str, const char *to_find)
{
	size_t	res;
	size_t	offset;
	char	*buf;

	res = 0;
	offset = ft_strlen(to_find);
	if ((buf = (char *)str))
		while ((buf = ft_strstr(buf, to_find)))
		{
			res++;
			buf += offset;
		}
	return (res);
}
