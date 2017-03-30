/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mato <rde-mato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:25:47 by rde-mato          #+#    #+#             */
/*   Updated: 2017/01/24 22:18:08 by rde-mato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../includes/mlx.h"
# include "../includes/get_next_line.h"
# include "../includes/libft.h"

# define WHI        0x00FFFFFF
# define RED        0x00FF0000
# define GRE        0x0000FF00
# define BLU        0x000000FF
# define C1         0x00550000
# define C2         0x00AA0000
# define C4         0x00005500
# define C5         0x0000AA00
# define C7         0x00000055
# define C8         0x000000AA

# define ESC        53
# define UP         126
# define DOWN       125
# define RIGHT      124
# define LEFT       123
# define PLUS       24
# define MINU       27
# define PUP        116
# define PDN        121
# define SPACE      49
# define TSB        46

# define NAME       "Feel Da Fap"
# define WI         1920
# define HE         1080

# define POSXA      WI / 20
# define POSYA      HE - HE / 10
# define MPWID      e->map.width
# define MPHEI      e->map.height

# define ZM         e->zoom
# define ZMMAX      200
# define H          e->h
# define Z          e->map.data
# define TX         (float)e->ctrl.mpx / 200
# define TY         (float)e->ctrl.mpy / 100

# define COSX 		e->mat.cosx
# define COSY		e->mat.cosy
# define SINX 		e->mat.sinx
# define COSY2		e->mat.cosy2
# define SINY2		e->mat.siny2
# define COSX2		e->mat.cosx2
# define SINX2		e->mat.sinx2

typedef struct	s_ctrl
{
	int			mpx;
	int			mpy;
	int			code;
	int			zoom;
	int			h;
}				t_ctrl;

typedef struct	s_l
{
	int			x;
	int			y;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			color;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
}				t_l;

typedef struct	s_map
{
	char		*filename;
	int			**data;
	int			height;
	int			width;
}				t_map;

typedef struct	s_mat
{
	float		cosx;
	float		cosy;
	float		sinx;
	float		cosy2;
	float		siny2;
	float		cosx2;
	float		sinx2;
}				t_mat;

typedef struct	s_fdf
{
	char		*title;
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixel_img;
	int			bpp;
	int			s_line;
	int			ed;
	int			width;
	int			height;
	int			zoom;
	int			h;
	int			yoffset;
	int			xoffset;
	int			helper;
	int			tsb;
	t_map		map;
	t_ctrl		ctrl;
	t_l			l;
	t_mat		mat;
}				t_fdf;

/*
**              bonus.c
*/
void			drawaxis(t_fdf *e);
void			colorselect(int keycode, t_fdf *e);
void			helper(t_fdf *e);
void			tsb(t_fdf *e);

/*
**              ctrl.c
*/
void			scale(int keycode, t_fdf *e);
void			scaleheight(int keycode, t_fdf *e);
void			straf(int keycode, t_fdf *e);
int				hook_mousemove(int x, int y, t_fdf *e);
int				hook_keypressed(int keycode, t_fdf *e);

/*
**              drawline.c
*/
void			drawlineh(t_fdf *e);
void			drawlinev(t_fdf *e);
void			drawline(t_fdf *e);

/*
**              drawmap.c
*/
void			drawmaph(t_fdf *e);
void			drawmapv(t_fdf *e);
void			drawmap(t_fdf *e);

/*
**              image.c
*/
void			mlx_pixel_put_image(t_fdf *e);
void			clearimage(t_fdf *e);
void			refreshimg(t_fdf *e);

/*
**              main.c
*/

int				free4all(t_fdf *e);
void			initstruct(t_fdf *e);
void			initmenelebexe(t_fdf *e);

/*
**              readmap.c
*/
void			getmapheight(t_map *map);
void			getmapwidth(t_map *map);
void			linetotab(int fd, char ***tab);
void			checkmaperror(t_map *map, char **tab);
void			fillmap(t_map *map);

#endif
