/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 18:22:54 by rde-mato          #+#    #+#             */
/*   Updated: 2017/01/30 16:16:45 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		mlx_pixel_put_image(t_fdf *e)
{
	int		i;

	i = ((e->l.x * e->bpp / 8) + (e->l.y * e->s_line));
	if (i >= 0 && i < e->s_line * HE && e->l.x >= 0 && e->l.x < WI)
	{
		e->pixel_img[i] = e->l.color;
		e->pixel_img[++i] = e->l.color >> 8;
		e->pixel_img[++i] = e->l.color >> 16;
	}
}

void		clearimage(t_fdf *e)
{
	int		i;

	i = -1;
	while (++i < WI * HE * 4)
		e->pixel_img[i] = 0;
}

void		refreshimg(t_fdf *e)
{
	ZM = e->ctrl.zoom;
	H = e->ctrl.h;
	clearimage(e);
	drawmap(e);
	drawaxis(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 5, WHI, e->map.filename);
	if (e->helper)
		helper(e);
	if (e->tsb)
		tsb(e);
}
