/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 04:02:18 by rde-mato          #+#    #+#             */
/*   Updated: 2016/11/13 08:29:01 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	nbmots(char const *str, char c)
{
	size_t	res;
	size_t	j;

	res = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] == c)
			j++;
		if (str[j])
			res++;
		while (str[j] != c && str[j])
			j++;
	}
	return (res);
}

static int	lenmot(char const *s, int pos, char c)
{
	int		res;

	res = 0;
	while (s[pos] != c && s[pos] != 0)
	{
		pos++;
		res++;
	}
	return (res);
}

static void	filltab(char *dest, char const *str, size_t pos, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dest[i] = str[pos];
		i++;
		pos++;
	}
	dest[i] = '\0';
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	pos;
	int		nmots;
	int		j;

	pos = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	nmots = nbmots(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (nmots + 1))))
		return (NULL);
	while (j < nmots)
	{
		while (s[pos] == c)
			pos++;
		if (!(res[j] = (char *)malloc(sizeof(char) * (lenmot(s, pos, c) + 1))))
			return (NULL);
		filltab(res[j], s, pos, lenmot(s, pos, c));
		while (s[pos] != c && s[pos])
			pos++;
		j++;
	}
	res[j] = NULL;
	return (res);
}
