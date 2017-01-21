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

int						move_f(t_frctl *f, double x, double y)
{
	double	d[2];

	d[0] = (f->x2 - f->x1);
	d[1] = (f->y2 - f->y1);
	if (x > 0)
	{
		f->x1 += d[0] * x;
		f->x2 = f->x1 + d[0];
	}
	else
	{
		f->x1 -= d[0] * -x;
		f->x2 = f->x1 + d[0];
	}
	if (y > 0)
	{
		f->y1 += d[1] * y;
		f->y2 = f->y1 + d[1];
	}
	else
	{
		f->y1 -= d[1] * -y;
		f->y2 = f->y1 + d[1];
	}
	return (0);
}


void			zoom_in(int x, int y, t_env *env)
{
	env->zoom *= 2;
	env->tmpx = env->x1 + x * (env->x2 - env->x1) / (WIN_X - 50);
	env->tmpy = env->y1 + y * (env->y2 - env->y1) / (WIN_Y - 50);
	env->tmpx2 = env->x1;
	env->tmpy2 = env->y1;
	env->x1 = env->tmpx - (env->x2 - env->x1) / 4;
	env->x2 = env->tmpx + (env->x2 - env->tmpx2) / 4;
	env->y1 = env->tmpy - (env->y2 - env->y1) / 4;
	env->y2 = env->tmpy + (env->y2 - env->tmpy2) / 4;
	env->frctl.settings.max_iter += 5;
}

void			zoom_out(int x, int y, t_env *env)
{
	if (env->zoom > 125)
	{
		env->zoom /= 2;
		env->tmpx = env->x1 + x * (env->x2 - env->x1) / WIN_X;
		env->tmpy = env->y1 + y * (env->y2 - env->y1) / WIN_Y;
		env->tmpx2 = env->x1;
		env->tmpy2 = env->y1;
		env->x1 = env->tmpx - (env->x2 - env->x1);
		env->x2 = env->tmpx + (env->x2 - env->tmpx2);
		env->y1 = env->tmpy - (env->y2 - env->y1);
		env->y2 = env->tmpy + (env->y2 - env->tmpy2);
		env->max -= 5;
	}
}

int				mouse(int kc, int x, int y, t_env *env)
{
	ft_bzero(env->data, WIN_Y * WIN_X * 4);
	if (y > 0 && env->check)
	{
		if ((kc == 1 || kc == 5) && x <= WIN_X)
			ft_zoom_in(x, y, env);
		if ((kc == 2 || kc == 4) && x <= WIN_X)
			ft_zoom_out(x, y, env);
	}
	env->check = 1;
	return (1);
}



int				key(int keycode, t_env *env)
{
	t_frctl	*f;

	f = &env->frctl;
	if (keycode == 124)
		move_f(f, -0.2, 0.0);
	if (keycode == 123)
		move_f(f, 0.2, 0.0);
	if (keycode == 126)
		move_f(f, 0.0, -0.2);
	if (keycode == 125)
		move_f(f, 0.0, 0.2);
	if (keycode == 5)
		zoom_in(f, 0.3);
	if (keycode == 4)
		zoom_out(f, -0.3);
	if (keycode == 15)
		f->color = 16;
	if (keycode == 9)
		f->color = 8;
	if (keycode == 11)
		f->color = 0;
	if (keycode == 53)
		exit(0);
	fractals_compute(env);
	return (0);
}

int				mouse_motion(int x, int y, t_env *env)
{
	t_frctl	*f;

	f = &env->frctl;
	f->c_r = (double)x / WIN_WIDTH;
	f->c_i = (double)y / WIN_HEIGHT;
	fractals_compute(env);
	return (0);
}


int				main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		env.mlx = mlx_init(); // initialize mlx server
		env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
		mlx_hook(env.win, 2, (1L << 0), key, &env);
		mlx_mouse_hook(env.win, mouse, &env);
		if (av[1][0] == '1' && av[1][1] == 0)
			init_mandelbrot(&env);
		else if (av[1][0] == '2' && av[1][1] == 0)
			init_julia(&env);
		else if (av[1][0] == '3' && av[1][1] == 0)
			init_burningship(&env);
		else
			ft_error("too much arguments or not enough");
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