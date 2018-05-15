/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:59:33 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/06 22:10:06 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	char	*buf_s;
	char	*buf_e;
	size_t	l;
	size_t	n;

	res = NULL;
	n = 0;
	if (!s)
		return (res);
	buf_s = (char *)s;
	while (buf_s && *buf_s && (ft_strchr(" \n\t", *(buf_s)) != NULL))
		buf_s++;
	l = ft_strlen(buf_s);
	buf_e = buf_s + l;
	while (buf_e > buf_s && (ft_strchr(" \n\t", *(buf_e--)) != NULL))
		n++;
	if ((res = ft_strnew(l - n + 1)))
		res = ft_strncpy(res, buf_s, l - n + 1);
	return (res);
}
