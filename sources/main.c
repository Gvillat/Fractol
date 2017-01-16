#include "../includes/fractol.h"

/*
**.Error handling and displaying
*/

void	ft_error(char *s)
{
	if (s == NULL)
		perror("error");
	else
	{
		ft_putstr("error: ");
		ft_putstr(s);
		ft_putstr(".\n");
	}
	exit(-1);
}

void clear_image(char **buff)
{
	int i;

	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH * 4)
		(*buff)[i++] = 0;
}

int 		key(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126)  // up
	{
		env->frctl.y1 += 0.5;
		env->frctl.y2 += 0.5;
	}
	if (keycode == 125)  // down
	{
		env->frctl.y1 -= 0.5;
		env->frctl.y2 -= 0.5;
	}
	if (keycode == 124)  // right
	{
		env->frctl.x1 -= 0.5;
		env->frctl.x2 -= 0.5;
	}
	if (keycode == 123)  // left
	{
		env->frctl.x1 += 0.5;
		env->frctl.x2 += 0.5;
	}
	if (keycode == 69)  // plus +
		env->frctl.settings.max_iter += 5;
	if (keycode == 78)  // moins -
		env->frctl.settings.max_iter -= 5;
	clear_image(&env->im_buf);
	put_image(env);
	return (1);
}

int						zoom_f(t_env *env, double s)
{
	if (s > 0)
	{
		env->frctl.x1 += (env->frctl.x2 - env->frctl.x1) * s;
		env->frctl.y1 += (env->frctl.y2 - env->frctl.y1) * s;
		env->frctl.x2 -= (env->frctl.x2 - env->frctl.x1) * s;
		env->frctl.y2 -= (env->frctl.y2 - env->frctl.y1) * s;
	}
	else
	{
		env->frctl.x1 -= (env->frctl.x2 - env->frctl.x1) * -s;
		env->frctl.y1 -= (env->frctl.y2 - env->frctl.y1) * -s;
		env->frctl.x2 += (env->frctl.x2 - env->frctl.x1) * -s;
		env->frctl.y2 += (env->frctl.y2 - env->frctl.y1) * -s;
	}
	return (0);
}

int  mouse(int bp, int x, int y t_env *env)
{
	if (bp == 4)  // scroll-up
	{
		zoom_f(env, 0.05);
	}
	if (bp == 5)  // scroll-down
	{
		zoom_f(env, -0.05);
	}
	clear_image(&env->im_buf);
	put_image(env);
	return (1);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac >= 2 && (ft_strequ(av[1], "mandelbrot") || ft_strequ(av[1], "julia") || ft_strequ(av[1], "burningship")))
	{
		env.mlx = mlx_init(); // initialize mlx server
		env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol"); // set a window
		init_fractal(&env.frctl, av[1]);
		put_image(&env); // create, process and display image
		mlx_mouse_hook(env.win, &mouse, &env);
		mlx_key_hook(env.win, &key, &env);

		// mlx_hook()
		mlx_loop(env.mlx);
	}
	else
		ft_error("too much arguments or not enough");

	return (0);
}


// faire la fct draw
// faire le menu
//mouse hook
//expose
//color
voila