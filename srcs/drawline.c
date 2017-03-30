/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:25:33 by rde-mato          #+#    #+#             */
/*   Updated: 2017/01/24 20:52:16 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		drawlineh(t_fdf *e)
{
	int		i;
	int		cumul;

	cumul = e->l.dx / 2;
	i = -1;
	while (++i < e->l.dx)
	{
		e->l.x += e->l.xinc;
		cumul += e->l.dy;
		if (cumul >= e->l.dx)
		{
			cumul -= e->l.dx;
			e->l.y += e->l.yinc;
		}
		mlx_pixel_put_image(e);
	}
}

void		drawlinev(t_fdf *e)
{
	int		i;
	int		cumul;

	cumul = e->l.dy / 2;
	i = -1;
	while (++i < e->l.dy)
	{
		e->l.y += e->l.yinc;
		cumul += e->l.dx;
		if (cumul >= e->l.dy)
		{
			cumul -= e->l.dy;
			e->l.x += e->l.xinc;
		}
		mlx_pixel_put_image(e);
	}
}

void		drawline(t_fdf *e)
{
	int		i;

	e->l.x = e->l.x0;
	e->l.y = e->l.y0;
	e->l.dx = e->l.x1 - e->l.x0;
	e->l.dy = e->l.y1 - e->l.y0;
	e->l.xinc = (e->l.dx > 0) ? 1 : -1;
	e->l.yinc = (e->l.dy > 0) ? 1 : -1;
	e->l.dx = ft_abs(e->l.dx);
	e->l.dy = ft_abs(e->l.dy);
	mlx_pixel_put_image(e);
	if (e->l.dx > e->l.dy)
		drawlineh(e);
	else
		drawlinev(e);
}
