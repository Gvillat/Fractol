#include "../includes/fractol.h"

void        fractals_compute(t_env *env, char *name)
{
	int		x;
	int		y;
	t_frctl	frctl;
	t_ptr ptr;

	x = -1;
	init_fractal(&frctl, name, &ptr);
	while(++x < WIN_WIDTH)
	{
		while (++y < WIN_HEIGHT)
		{
			ptr.fct[frctl.type](x, y , &frctl, env);
		}
		y = -1;
	}
}

void		init_fractal(t_frctl *frctl, char *name, t_ptr *ptr)
{
	if (ft_strequ(name, "julia"))
		init_julia(frctl);
	else if (ft_strequ(name, "burningship"))
		init_burningship(frctl);
	if (ft_strequ(name, "mandelbrot"))
		init_mandelbrot(frctl);
	ptr->fct[0] = mandelbrot;
	ptr->fct[1] = julia;
	ptr->fct[2] = burningship;
}