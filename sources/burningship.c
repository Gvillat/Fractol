#include "../includes/fractol.h"

/*
** Init burningship structure.
*/

void		init_burningship(t_frctl *frctl)
{
	frctl->type = 2;
	frctl->x1 = -0.9;
	frctl->x2 = 0;
	frctl->y1 = -1.3;
	frctl->y2 = 0;
	frctl->settings.zoom_x = WIN_WIDTH / (frctl->x2 - frctl->x1);
	frctl->settings.zoom_y = WIN_HEIGHT / (frctl->y2 - frctl->y1);
	frctl->settings.max_iter = 60;
}

/*
** buddhabrot function.
*/

void        burningship(int x, int y, t_frctl *frctl, t_env *env)
{
	int		i;
	float	tmp;

	i = 0;
	frctl->c_r = x / frctl->settings.zoom_x + frctl->x1;
	frctl->c_i = y / frctl->settings.zoom_y + frctl->y1;
	frctl->z_r = 0;
	frctl->z_i = 0;
	while ((frctl->z_r * frctl->z_r + frctl->z_i * frctl->z_i) < 4
			&& i < frctl->settings.max_iter) // while(module < 4 and i < max iterations)
	{
		tmp = frctl->z_r;
		frctl->z_r = frctl->z_r * frctl->z_r - frctl->z_i * frctl->z_i + frctl->c_r;
		frctl->z_i = 2 * frctl->z_i * tmp + frctl->c_i;
		i++;
		if (frctl->z_r * frctl->z_r + frctl->z_i * frctl->z_i > 10)
			break;
	}
	if (i == frctl->settings.max_iter)
	{
		put_pixel(env, x, y, 10405228);
	}
	else
	{
		put_pixel(env, x, y, i * 255 / frctl->settings.max_iter);
	}
}