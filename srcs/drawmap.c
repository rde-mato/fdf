/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:25:33 by rde-mato          #+#    #+#             */
/*   Updated: 2017/01/24 20:36:54 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		drawmaph(t_fdf *e)
{
	int x;
	int y;
	int i;
	int j;

	j = 0;
	y = -e->map.height / 2 + e->yoffset;
	while (++y < e->map.height / 2 + e->map.height % 2 + e->yoffset + 1)
	{
		i = 0;
		x = -e->map.width / 2 + e->xoffset;
		e->l.x0 = (COSX * (x + 1) - SINX * y) * ZM + WI / 2;
		e->l.y0 = (SINX * (x + 1) + COSX * y) * COSY * ZM + HE / 2;
		e->l.y0 += (SINY2 * H * Z[j++][i] * COSY2);
		while (++x < e->map.width / 2 + e->map.width % 2 + e->xoffset)
		{
			e->l.x1 = (COSX * (x + 1) - SINX * y) * ZM + WI / 2;
			e->l.y1 = (SINX * (x + 1) + COSX * y) * COSY * ZM + HE / 2;
			e->l.y1 += SINY2 * H * Z[j - 1][i++ + 1] * COSY2;
			drawline(e);
			e->l.x0 = e->l.x1;
			e->l.y0 = e->l.y1;
		}
	}
}

void		drawmapv(t_fdf *e)
{
	int x;
	int y;
	int i;
	int j;

	i = 0;
	x = -e->map.width / 2 + e->xoffset;
	while (++x < e->map.width / 2 + e->map.width % 2 + e->xoffset + 1)
	{
		j = 0;
		y = -e->map.height / 2 + e->yoffset;
		e->l.x0 = (COSX * x - SINX * (y + 1)) * ZM + WI / 2;
		e->l.y0 = (SINX * x + COSX * (y + 1)) * COSY * ZM + HE / 2;
		e->l.y0 += SINY2 * H * Z[j][i++] * COSY2;
		while (++y < e->map.height / 2 + e->map.height % 2 + e->yoffset)
		{
			e->l.x1 = (COSX * x - SINX * (y + 1)) * ZM + WI / 2;
			e->l.y1 = (SINX * x + COSX * (y + 1)) * COSY * ZM + HE / 2;
			e->l.y1 += SINY2 * H * Z[j++ + 1][i - 1] * COSY2;
			drawline(e);
			e->l.x0 = e->l.x1;
			e->l.y0 = e->l.y1;
		}
	}
}

void		drawmap(t_fdf *e)
{
	e->mat.cosx = cos(TX);
	e->mat.cosy = cos(TY);
	e->mat.sinx = sin(TX);
	e->mat.cosy2 = cos(TY / 2);
	e->mat.siny2 = sin(TY / 2);
	e->mat.cosx2 = cos(TX / 2);
	e->mat.sinx2 = sin(TX / 2);
	drawmaph(e);
	drawmapv(e);
}
