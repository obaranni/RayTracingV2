/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:54:09 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/26 22:11:41 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_substrs_count(const char *str, char c)
{
	int		res;
	char	*buf;

	res = 0;
	buf = (char *)str;
	while (*buf++)
		if (*(buf - 1) != c && (*buf == c || !*buf))
			res++;
	return (res);
}

static int	ft_substr_len(const char *s, char d)
{
	int		i;

	i = 0;
	while (*s && *s != d)
	{
		i++;
		s++;
	}
	return (i);
}

static char	**ft_del_str_arr(char **ar, size_t l)
{
	while (l-- > 0)
		ft_strdel(ar + l);
	free(ar);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	scount;
	size_t	slen;
	size_t	i;

	res = NULL;
	if (!s)
		return (res);
	scount = ft_substrs_count(s, c);
	if ((res = (char **)malloc(sizeof(char *) * (scount + 1))))
	{
		i = 0;
		while (*s && i < scount)
		{
			while (*s == c)
				s++;
			slen = ft_substr_len((char *)s, c);
			if (!(*(res + i++) = ft_strncpy(ft_strnew(slen), s, slen)))
				return (ft_del_str_arr(res, --i));
			s += slen;
		}
		*(res + scount) = 0;
	}
	return (res);
}
