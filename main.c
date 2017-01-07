#include "fractol.h"

/*
**.Error handling and displaying
*/

// void	ft_error(char *s)
// {
// 	if (s == NULL)
// 		perror("error");
// 	else
// 	{
// 		ft_putstr("error: ");
// 		ft_putstr(s);
// 		ft_putstr(".\n");
// 	}
// 	exit(-1);
// }

int		main(void)
{
	t_env	env;

	// if (ac == 2)
	// {
	env.mlx = mlx_init(); // initialize mlx server
	env.win = mlx_new_window(env.mlx, 640, 480, "Fractol"); // set a window
    // Instead of followings functions, we'll use put_image now:
	// env.im = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT); // create a new image in memory
	// env.im_buf = mlx_get_data_addr(env.im, &env.bpp, &env.sl, &env.endian);
	put_image(&env); // create, process and display image
	mlx_loop(env.mlx);
	// }
	// else
	// 	ft_error("too much arguments or not enough");
	return (0);
}
