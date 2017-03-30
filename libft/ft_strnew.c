/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:01:55 by rde-mato          #+#    #+#             */
/*   Updated: 2016/11/15 10:22:29 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (ft_memset(res, '\0', size + 1));
}
