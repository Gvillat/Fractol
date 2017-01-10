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

int		main(int ac, char **av)
{
	t_env	env;
	int i;

	i = 1;
	// while (av[i])
	// {
		if (ac >= 2 && (ft_strequ(av[i], "mandelbrot") || ft_strequ(av[i], "julia") || ft_strequ(av[i], "burningship")))
		{
			env.mlx = mlx_init(); // initialize mlx server
			// Instead of followings functions, we'll use put_image now:
			// env.im = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT); // create a new image in memory
			// env.im_buf = mlx_get_data_addr(env.im, &env.bpp, &env.sl, &env.endian);
			put_image(&env, av[i]); // create, process and display image
			mlx_loop(env.mlx);
		}
		else
			ft_error("too much arguments or not enough");
		i++;
	// }
	return (0);
}
