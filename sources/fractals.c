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
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			// mandelbrot(x, y, &frctl, env);
			ptr.fct[frctl.type](x, y , &frctl, env);
		}
	}
}

void		init_fractal(t_frctl *frctl, char *name, t_ptr *ptr)
{
	if (ft_strequ(name, "julia"))
		init_julia(frctl);
	else if (ft_strequ(name, "buddhabrot"))
		init_buddhabrot(frctl);
	if (ft_strequ(name, "mandelbrot"))
		init_mandelbrot(frctl);
	ptr->fct[0] = mandelbrot;
	ptr->fct[1] = julia;
	ptr->fct[2] = buddhabrot;
}