/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 23:49:17 by rde-mato          #+#    #+#             */
/*   Updated: 2017/01/24 22:18:56 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int		nextfuckingshit(char **stock, char **line)
{
	char				*tmp;

	if (*stock && (tmp = ft_strchr(*stock, '\n')))
	{
		*line = ft_strsub(*stock, 0, ft_strlen(*stock) - ft_strlen(tmp));
		*stock = ft_memmove(*stock, tmp + 1, ft_strlen(tmp));
		return (1);
	}
	return (0);
}

static int		readshit(int fd, char **stock, char **line)
{
	int					ret;
	char				buf[BUFF_SIZE + 1];
	char				*tmp;
	char				*tmpstock;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmpstock = ft_strjoin(*stock, buf);
		if (*stock && **stock)
			free(*stock);
		*stock = tmpstock;
		if (nextfuckingshit(stock, line))
			return (1);
	}
	if (ret == -1 || (ret == 0 && !(*stock)))
		return (ret);
	if ((tmp = ft_strchr(*stock, '\0')) && (tmp != *stock))
	{
		*line = ft_strdup(*stock);
		*stock = "\0";
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *stock[NBFDMAX];

	if (fd < 0 || !line || BUFF_SIZE < 1 || fd > NBFDMAX)
		return (-1);
	if (nextfuckingshit(&stock[fd], line))
		return (1);
	return (readshit(fd, &stock[fd], line));
}
