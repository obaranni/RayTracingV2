/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymitelsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 23:03:16 by ymitelsk          #+#    #+#             */
/*   Updated: 2016/12/13 22:00:52 by ymitelsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;

	while (*alst)
	{
		buf = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = buf;
	}
	alst = NULL;
}
