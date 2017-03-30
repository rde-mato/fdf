/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:05:52 by rde-mato          #+#    #+#             */
/*   Updated: 2016/11/13 15:40:46 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(s1) + 1;
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (0);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	return (res);
}
