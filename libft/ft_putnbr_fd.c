/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 19:28:56 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/21 23:14:32 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	buf;

	buf = (long)n;
	if (buf < 0)
	{
		ft_putchar_fd('-', fd);
		buf *= -1;
	}
	if (buf > 9)
		ft_putnbr_fd((int)(buf / 10), fd);
	ft_putchar_fd(buf % 10 + 48, fd);
}
