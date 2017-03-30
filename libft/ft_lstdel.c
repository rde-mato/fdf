/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:39:32 by rde-mato          #+#    #+#             */
/*   Updated: 2016/11/15 12:03:03 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *listnext;

	list = *alst;
	if (&*alst && *alst && alst)
	{
		while (list)
		{
			listnext = list->next;
			del((*list).content, (*list).content_size);
			free(list);
			list = listnext;
		}
	}
	*alst = list;
}
