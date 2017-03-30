/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:50:05 by rde-mato          #+#    #+#             */
/*   Updated: 2016/11/13 15:50:12 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s) + 1;
		if (!(res = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		while (s[i])
		{
			res[i] = f((char)s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
