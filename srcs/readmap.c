/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:26:48 by rde-mato          #+#    #+#             */
/*   Updated: 2017/02/10 19:47:31 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		getmapheight(t_map *map)
{
	int		fd;
	char	buf;

	map->height = 0;
	if ((fd = open(map->filename, O_RDONLY)) < 0)
		exit(write(2, "Can't open map\n", 15));
	while (read(fd, &buf, 1))
		if (buf == '\n')
			map->height++;
	close(fd);
}

void		getmapwidth(t_map *map)
{
	int		fd;
	char	*line;
	char	**tab;

	map->width = 0;
	if ((fd = open(map->filename, O_RDONLY)) < 0)
		exit(write(2, "Can't open map\n", 15));
	linetotab(fd, &tab);
	while (tab[map->width])
		map->width++;
	ft_freetab(tab);
}

void		linetotab(int fd, char ***tab)
{
	char *line;

	get_next_line(fd, &line);
	*tab = ft_strsplit(line, ' ');
	free(line);
}

void		checkmaperror(t_map *map, char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if (i != map->width)
		exit(write(2, "Map error\n", 10));
}

void		fillmap(t_map *map)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**tab;

	getmapheight(map);
	getmapwidth(map);
	if ((fd = open(map->filename, O_RDONLY)) < 0)
		exit(write(2, "Can't open map\n", 15));
	if (!(map->data = (int **)malloc(sizeof(int *) * map->height)))
		exit(write(2, "Malloc error mapheight\n", 23));
	i = -1;
	while (++i < map->height)
	{
		linetotab(fd, &tab);
		checkmaperror(map, tab);
		if (!(map->data[i] = (int *)malloc(sizeof(int) * map->width)))
			exit(write(2, "Malloc error mapwidth\n", 22));
		j = -1;
		while (++j < map->width)
			map->data[i][j] = ft_atoi(tab[j]);
		ft_freetab(tab);
	}
	close(fd);
}
