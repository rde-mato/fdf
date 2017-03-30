/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:49:22 by rde-mato          #+#    #+#             */
/*   Updated: 2016/11/13 15:55:27 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (s)
	{
		while (i < len)
		{
			res[i] = s[start];
			start++;
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
