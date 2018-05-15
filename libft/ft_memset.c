/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:29:31 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/02 19:57:13 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	void	*tmp;

	i = 0;
	tmp = b;
	while (i++ < len)
		*(unsigned char *)b++ = (unsigned char)c;
	return (tmp);
}
