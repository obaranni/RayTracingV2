/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:24:50 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/28 22:56:50 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2)
		if (ft_strlen(s1) == ft_strlen(s2) ||
				(ft_strlen(s1) >= n && ft_strlen(s2) >= n))
			if (!ft_strncmp(s1, s2, n))
				return (1);
	return (0);
}
