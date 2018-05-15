/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:01:08 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/12 23:00:56 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	res = NULL;
	if ((res = (t_list *)malloc(sizeof(t_list))))
	{
		if (content)
		{
			res->content = ft_memcpy(malloc(content_size),
										content, content_size);
			res->content_size = content_size;
		}
		else
		{
			res->content = NULL;
			res->content_size = 0;
		}
		res->next = NULL;
	}
	return (res);
}
