/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:35:23 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/21 23:16:54 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	if (n == 0)
		return (0);
	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((*(ss1 + i) == *(ss2 + i)) &&
		(*(ss1 + i) && *(ss2 + i)) && (i + 1 < n))
		i++;
	return (*(ss1 + i) - *(ss2 + i));
}
