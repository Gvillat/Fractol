#include "../includes/fractol.h"

/*
** Init julia structure.
*/

void		init_julia(t_env *env)
{
	env->im = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT); // create a new image in memory
	env->frctl.type = 1;
	env->frctl.x1 = -1.5;
	env->frctl.x2 = 1.5;
	env->frctl.y1 = -1.5;
	env->frctl.color = 16;
	env->frctl.y2 = 1.5;
	env->frctl.c_r = 0.285;
	env->frctl.c_i = 0.01;
	env->frctl.settings.zoom_x = WIN_WIDTH / (env->frctl.x2 - env->frctl.x1);
	env->frctl.settings.zoom_y = WIN_HEIGHT / (env->frctl.y2 - env->frctl.y1);
	env->frctl.settings.max_iter = 100;
	mlx_hook(env->win, 6, (1L << 6), mouse_motion, env);
	fractals_compute(env);
}

/*
** Julia function.
*/

void        julia(int x, int y, t_frctl *frctl, t_env *env)
{
	int		i;
	float	tmp;
	int 	dv;

	i = 0;
	frctl->z_r = x / frctl->settings.zoom_x + frctl->x1;
	frctl->z_i = y / frctl->settings.zoom_y + frctl->y1;
	while ((frctl->z_r * frctl->z_r + frctl->z_i * frctl->z_i) < 4
			&& i < frctl->settings.max_iter) // while(module < 4 and i < max iterations)
	{
		tmp = frctl->z_r;
		frctl->z_r = frctl->z_r * frctl->z_r - frctl->z_i * frctl->z_i + frctl->c_r;
		frctl->z_i = 2 * frctl->z_i * tmp + frctl->c_i;
		i++;
	}
	dv = 255 / frctl->settings.max_iter;
	if (i == frctl->settings.max_iter)
	{
		put_pixel(env, x, y, (i * dv << frctl->color));
	}
}