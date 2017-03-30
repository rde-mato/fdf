/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:18:51 by rde-mato          #+#    #+#             */
/*   Updated: 2016/11/15 14:35:13 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t len2;

	if (!*little)
		return ((char *)big);
	len2 = ft_strlen(little);
	while (*big && len-- >= len2)
	{
		if (*big == *little && !ft_memcmp(big, little, len2))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
