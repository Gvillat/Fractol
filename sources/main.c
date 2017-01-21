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

int				main(int ac, char **av)
{
	t_env	env;

	if (ac == 2 && av[1]  && (ft_strequ(av[1], "mandelbrot")
	|| ft_strequ(av[1], "julia") || ft_strequ(av[1], "burningship")))
	{
		env.mlx = mlx_init(); // initialize mlx server
		env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
		if (ft_strequ(av[1], "julia"))
			env->draw = init_julia;
		else if (ft_strequ(av[1], "mandelbrot"))
			env->draw = init_mandelbrot;
		else if (ft_strequ(av[1], "burningship"))
		env->draw = init_burningship;
		env.draw(&env);
		mlx_mouse_hook(env.win, zoom, &env);
		mlx_hook(env.win, 2, (1L << 0), key, &env);
		mlx_loop(env.mlx);
	}
	else
		display_menu();
	return (0);
}

//menu
//couleur psyche
// bonus ?