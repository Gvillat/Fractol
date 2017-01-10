#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "minilibx_macos/mlx.h"
// # include "mlx.h"
# include "libft/libft.h"

# define WIN_WIDTH 270
# define WIN_HEIGHT 240

/*
** This structure is for shared options for every fractals.
*/

typedef struct		s_fra
{
	float			zoom_x;
	float			zoom_y;
	int				max_iter;
}					t_fra;

/*
** This structure is for all mandelbrot fractal's concerns.
*/

typedef struct      s_mdl
{
	float			x1;
	float			y1;
	float			x2;
	float			y2;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	t_fra			settings;
}                   t_mdl;

/*
** This structure store environment settings for mlx purpose.
*/

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*im;
	char			*im_buf;
	int 			bpp;
	int 			endian;

	int 			sl;

	int				size_x;
	int				size_y;
}					t_env;

/*
** images.c
*/

void		put_pixel(t_env *env, int x, int y, int color);
int			put_image(t_env *env);

/*
** fractals.c
*/

void		fractals_compute(t_env *env);

/*
** mandelbrot.c
*/

void		julia(int x, int y, t_mdl *mdl, t_env *env);
void		mandelbrot(int x, int y, t_mdl *mdl, t_env *env);

#endif
