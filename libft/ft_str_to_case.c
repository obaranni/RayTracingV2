/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 22:52:58 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/20 22:44:39 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_to_case(const char *str, int up_case, int to_new)
{
	char	*res;
	size_t	i;

	i = -1;
	res = (char *)(to_new ? ft_strcpy(ft_strnew(ft_strlen(str)), str) : str);
	while (*(str + ++i))
		*(res + i) = (up_case ? ft_toupper(*(str + i))
				: ft_tolower(*(str + i)));
	return (res);
}
