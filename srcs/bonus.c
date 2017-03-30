/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 21:48:12 by rde-mato          #+#    #+#             */
/*   Updated: 2017/01/24 18:51:02 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		drawaxis(t_fdf *e)
{
	int		tmp;

	tmp = e->l.color;
	e->l.x0 = POSXA;
	e->l.y0 = POSYA;
	e->l.x1 = cos(-TX) * ZM + POSXA;
	e->l.y1 = sin(TX) * cos(TY) * ZM + POSYA;
	e->l.color = RED;
	drawline(e);
	e->l.x1 = -sin(-TX) * ZM + POSXA;
	e->l.y1 = -cos(TX) * cos(TY) * ZM + POSYA;
	e->l.color = GRE;
	drawline(e);
	e->l.x1 = POSXA;
	e->l.y1 = sin(TY) * ZM + POSYA;
	e->l.color = BLU;
	drawline(e);
	e->l.color = tmp;
}

void		colorselect(int keycode, t_fdf *e)
{
	if (keycode == 18)
		e->l.color = C1;
	else if (keycode == 19)
		e->l.color = C2;
	else if (keycode == 20)
		e->l.color = RED;
	else if (keycode == 21)
		e->l.color = C4;
	else if (keycode == 23)
		e->l.color = C5;
	else if (keycode == 22)
		e->l.color = GRE;
	else if (keycode == 26)
		e->l.color = C7;
	else if (keycode == 28)
		e->l.color = C8;
	else if (keycode == 25)
		e->l.color = BLU;
	else if (keycode == 29)
		e->l.color = WHI;
	refreshimg(e);
}

void		helper(t_fdf *e)
{
	mlx_string_put(e->mlx, e->win, 1600, 5, WHI,
					"Moves : UP / DOWN / LEFT / RIGHT");
	mlx_string_put(e->mlx, e->win, 1600, 20, WHI, "Zoom : + / -");
	mlx_string_put(e->mlx, e->win, 1600, 35, WHI, "Height : Page UP / DOWN");
	mlx_string_put(e->mlx, e->win, 1600, 50, WHI, "Select Color : 0 to 9");
	mlx_string_put(e->mlx, e->win, 1600, 65, WHI, "Space to reset the world");
	mlx_string_put(e->mlx, e->win, 1600, 80, 0x00202020,
					"M = THE Secret Button");
}

void		tsb(t_fdf *e)
{
	mlx_string_put(e->mlx, e->win, 1670, 1055, C2, "SECRET BUTTON PRESSED !!!");
	e->tsb = 1;
}
