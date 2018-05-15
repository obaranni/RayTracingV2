/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:19:19 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/21 22:10:34 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;

	res = NULL;
	if (lst && f)
	{
		res = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		res->next = ft_lstmap(lst->next, f);
	}
	return (res);
}
