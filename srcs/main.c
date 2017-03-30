/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:40:43 by rde-mato          #+#    #+#             */
/*   Updated: 2017/02/10 19:50:11 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			free4all(t_fdf *e)
{
	int		i;

	i = -1;
	while (++i < e->map.height)
		free(e->map.data[i]);
	free(e->map.data);
	free(e->map.filename);
	free(e->mlx);
	free(e->win);
	free(e->img);
	free(e->pixel_img);
	if (e->tsb)
		system("afplay srcs/tsb.mp3");
	exit(0);
	return (666);
}

void		initstruct(t_fdf *e)
{
	e->ctrl.mpx = WI / 2 + WI / 4;
	e->ctrl.mpy = HE / 2;
	e->zoom = 1000 / e->map.width;
	e->h = e->zoom / 5;
	e->yoffset = -1;
	e->xoffset = -1;
	e->ctrl.zoom = 1000 / e->map.width;
	e->ctrl.h = e->zoom / 5;
	e->helper = 0;
	e->l.color = WHI;
	e->tsb = 0;
	refreshimg(e);
}

void		initmenelebexe(t_fdf *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WI, HE, "feel da fap");
	e->img = mlx_new_image(e->mlx, WI, HE);
	e->pixel_img = mlx_get_data_addr(e->img, &(e->bpp),
										&(e->s_line), &(e->ed));
}

int			main(int ac, char **av)
{
	t_fdf	e;

	if (ac != 2)
	{
		write(2, "usage : ./fdf filemapname\n", 26);
		return (0);
	}
	e.map.filename = ft_strdup(av[1]);
	fillmap(&e.map);
	initmenelebexe(&e);
	initstruct(&e);
	mlx_key_hook(e.win, hook_keypressed, &e);
	mlx_hook(e.win, 6, 0, hook_mousemove, &e);
	mlx_hook(e.win, 17, 1L << 17, free4all, &e);
	mlx_loop(e.mlx);
	return (0);
}
