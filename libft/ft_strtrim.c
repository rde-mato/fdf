/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:14:14 by rde-mato          #+#    #+#             */
/*   Updated: 2016/11/13 15:52:27 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const *endtotrim;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		++s;
	if (*s == '\0')
		return (ft_strnew(1));
	endtotrim = s + ft_strlen(s) - 1;
	while (*endtotrim == ' ' || *endtotrim == '\n' || *endtotrim == '\t')
		--endtotrim;
	return (ft_strsub(s, 0, endtotrim - s + 1));
}
