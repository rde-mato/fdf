/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:21:46 by rde-mato          #+#    #+#             */
/*   Updated: 2016/11/15 15:21:39 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map;
	t_list *maptmp;

	map = NULL;
	maptmp = NULL;
	if (lst)
	{
		if ((map = (t_list *)malloc(ft_lstlen(lst) * sizeof(t_list))))
		{
			map = f(ft_lstnew(lst->content, lst->content_size));
			maptmp = map;
			lst = lst->next;
			while (lst)
			{
				maptmp->next = f(ft_lstnew(lst->content, lst->content_size));
				maptmp = maptmp->next;
				lst = lst->next;
			}
			return (map);
		}
	}
	return (NULL);
}
