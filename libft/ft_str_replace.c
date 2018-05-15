/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:42:12 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/20 23:04:45 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iter(char **c, size_t *s, const char *to_rep, const char *to_find)
{
	if ((c[3] = ft_strstr(c[1], to_find)))
	{
		s[2] = c[3] - c[1];
		ft_strncpy(c[2], c[0], s[2]);
		ft_strcpy(c[2] + s[2], to_rep);
		c[2] += (s[2] + s[1]);
		c[0] += (s[2] + s[0]);
		c[1] += (s[2] + s[0]);
		return (0);
	}
	else
	{
		ft_strcpy(c[2], c[0]);
		return (1);
	}
}

char		*ft_str_replace(const char *str, const char *to_find,
						const char *to_rep, int ignore_case)
{
	char	*res;
	char	*c[4];
	size_t	s[3];

	if (*str)
	{
		s[0] = ft_strlen(to_find);
		s[1] = ft_strlen(to_rep);
		to_find = (ignore_case ? ft_str_to_case(to_find, 0, 1) : to_find);
		c[0] = (char *)str;
		c[1] = (ignore_case ? ft_str_to_case(c[0], 0, 1) : c[0]);
		res = ft_strnew(ft_strlen(str) + (s[1] - s[0])
				* ft_strstr_count(c[1], to_find));
		c[2] = res;
		while (*(c[1]))
			if (iter(c, s, to_rep, to_find))
				return (res);
		return (res);
	}
	return (NULL);
}
