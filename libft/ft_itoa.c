/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:13:27 by rde-mato          #+#    #+#             */
/*   Updated: 2016/11/13 12:10:02 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	sizeinttochar(int n)
{
	int		size;

	size = 0;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static int	intisneg(int *n)
{
	if (*n < 0)
	{
		*n = *n * -1;
		return (1);
	}
	return (0);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		neg;

	neg = intisneg(&n);
	size = sizeinttochar(n) + neg;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size] = '\0';
	if (neg)
		res[0] = '-';
	while (size - neg)
	{
		size--;
		res[size] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}
