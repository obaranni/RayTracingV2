/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:38:50 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/06 20:59:22 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = NULL;
	if (s1 && s2 && (res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		res = ft_strcpy(res, s1);
		ft_strcpy(ft_strchr(res, '\0'), s2);
	}
	return (res);
}
