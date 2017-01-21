#include "../includes/fractol.h"

/*
** Manage image buffer pixels by pixels, with RGB color coded into an int. For
** instance, RGB color 156-89-213 will be RGB hex 9C-59-D5 or RGB int 10246613.
** On our computer, pixels are stored in BGR. This function, may only work in
** our endian case.
*/

void		put_pixel(t_env *env, int x, int y, int color)
{
	int		i;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return;
	env->im_buf = mlx_get_data_addr(env->im, &(env->bpp), &(env->sl),
    &(env->endian));
	i = x * env->bpp / 8 + y * env->sl;
	env->im_buf[i] = color & 0xFF; // Blue
	env->im_buf[i + 1] = (color & 0xFF00) >> 8; // Green
	env->im_buf[i + 2] = (color & 0xFF0000) >> 16; // Red
}

/*
** Create a new image, get image buffer and compute fractals stored
** into image buffer (im_buf). Then, dump to window and destroy image from
** memory.
*/

