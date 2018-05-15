/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:12:25 by obaranni          #+#    #+#             */
/*   Updated: 2018/02/27 14:31:28 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

int			argument_check(int argc)
{
	if (argc > 6)
	{
		ft_putendl("Too many arguments!");
		exit(1);
	}
	if (argc < 2)
	{
		ft_putendl("Need an argument!");
		exit(1);
	}
	return (1);
}
