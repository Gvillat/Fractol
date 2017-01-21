#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
// # include "../minilibx_macos/mlx.h"
# include "mlx.h"
# include "../libft/libft.h"
# include "math.h"
# define WIN_WIDTH 600
# define WIN_HEIGHT 480


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
	int 			x;
	int 			y;
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
	t_frctl 		frctl;
	void			(*draw)(struct s_env*);
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
int			put_image(t_env *env);
int				mouse(int button, int x, int y, t_env *env);
void						move_f(t_frctl *f, double x, double y);
int	zoom(int key, int x, int y, t_env *env);
int				key(int keycode, t_env *env);
int				mouse_motion(int x, int y, t_env *env);
/*
** fractals.c
*/

void		fractals_compute(t_env *env);
t_env 		init_fractol(t_env env, void *mlx, char *name);

int				mouse_motion(int x, int y, t_env *env);
/*
** mandelbrot.c
*/

void		init_mandelbrot(t_env *env);
void		mandelbrot(int x, int y, t_frctl *frctl, t_env *env);


/*
** julia.c
*/

void		init_julia(t_env *env);
void		julia(int x, int y, t_frctl *frctl, t_env *env);

/*
** buddhabrot.c
*/

void		init_burningship(t_env *env);
void		burningship(int x, int y, t_frctl *frctl, t_env *env);

#endif
