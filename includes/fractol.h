#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "../minilibx_macos/mlx.h"
// # include "mlx.h"
# include "../libft/libft.h"
# include "math.h"
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000


/*
** This structure is for shared options for every fractals.
*/

typedef struct		s_opt
{
	float			zoom_x;
	float			zoom_y;
	int				max_iter;
}					t_opt;

/*
** This structure is for all fractal's concerns.
*/

typedef struct      s_frctl
{
	int				type;
	float			x1;
	float			y1;
	float			x2;
	float			y2;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	int				color;
	t_opt			settings;
}                   t_frctl;

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
** This structure is to call the good fractal.
*/

typedef struct		s_ptr
{
	void (*fct[3])(int, int, t_frctl*, t_env*);
}					t_ptr;

/*
** images.c
*/

void		put_pixel(t_env *env, int x, int y, int color);
int			put_image(t_env *env, char *name);

/*
** fractals.c
*/

void		fractals_compute(t_env *env, char* name);
void		init_fractal(t_frctl *frctl, char *name, t_ptr *ptr);


/*
** mandelbrot.c
*/

void		init_mandelbrot(t_frctl *frctl);
void		mandelbrot(int x, int y, t_frctl *frctl, t_env *env);


/*
** julia.c
*/

void		init_julia(t_frctl *frctl);
void		julia(int x, int y, t_frctl *frctl, t_env *env);

/*
** buddhabrot.c
*/

void		init_burningship(t_frctl *frctl);
void		burningship(int x, int y, t_frctl *frctl, t_env *env);

#endif
