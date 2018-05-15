/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bid_list_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:57:51 by ymitelsk          #+#    #+#             */
/*   Updated: 2018/02/27 13:56:52 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_bid_list		*add_bid_lst(t_bid_list *lst, void *data)
{
	t_bid_list	*res;

	if (lst)
	{
		res = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = (t_bid_list *)ft_memalloc(sizeof(t_bid_list));
		lst->next->prew = lst;
		lst = lst->next;
	}
	else
	{
		lst = (t_bid_list *)ft_memalloc(sizeof(t_bid_list));
		res = lst;
		lst->prew = NULL;
	}
	lst->next = NULL;
	lst->data = data;
	return (res);
}
