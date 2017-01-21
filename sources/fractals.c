#include "../includes/fractol.h"

void        fractals_compute(t_env *env)
{
	int		x;
	int		y;
	t_ptr 	ptr;
	
	x = -1;
	ptr.fct[0] = mandelbrot;
	ptr.fct[1] = julia;
	ptr.fct[2] = burningship;
	while(++x < WIN_WIDTH)
	{
		while (++y < WIN_HEIGHT)
		{
			ptr.fct[env->frctl.type](x, y , &env->frctl, env);
		}
		y = -1;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0); // dump image to window
}

// void		init_fractal(t_frctl *frctl, char *name)
// {
// 	if (ft_strequ(name, "julia"))
// 		init_julia(frctl);
// 	else if (ft_strequ(name, "burningship"))
// 		init_burningship(frctl);
// 	if (ft_strequ(name, "mandelbrot"))
// 		init_mandelbrot(frctl);
// }