#include "../includes/fractol.h"

void						move_f(t_frctl *f, double x, double y)
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
}

int	zoom(int key, int x, int y, t_env *env)
{
	double		tmp_x;
	double		tmp_y;

	tmp_x = ((double)x / env->frctl.settings.zoom_x + env->frctl.x1);
	tmp_y = ((double)y / env->frctl.settings.zoom_y + env->frctl.y1);
	if (key == 1 || key == 4)
	{
		env->frctl.settings.zoom_x *= 1.3;
		env->frctl.settings.zoom_y *= 1.3;
		env->frctl.x1 = tmp_x - ((double)x / env->frctl.settings.zoom_x);
		env->frctl.y1 = tmp_y - ((double)y / env->frctl.settings.zoom_y);
		env->frctl.settings.max_iter += 2;
	}
	if ((key == 2 || key == 5) && (env->frctl.settings.max_iter > 10))
	{
		env->frctl.settings.zoom_x *= 0.7;
		env->frctl.settings.zoom_y *= 0.7;
		env->frctl.x1 = tmp_x - ((double)x / env->frctl.settings.zoom_x);
		env->frctl.y1 = tmp_y - ((double)y / env->frctl.settings.zoom_y);
		env->frctl.settings.max_iter -= 2;
	}
	fractals_compute(env);
	return (1);
}

int				key(int keycode, t_env *env)
{
	t_frctl	*f;

	f = &env->frctl;
	if (keycode == 124)
		move_f(f, -0.2, 0.0);
	else if (keycode == 123)
		move_f(f, 0.2, 0.0);
	else if (keycode == 126)
		move_f(f, 0.0, -0.2);
	else if (keycode == 125)
		move_f(f, 0.0, 0.2);
	else if (keycode == 69) //+
	{
		env->frctl.settings.zoom_x *= 1.3;
		env->frctl.settings.zoom_y *= 1.3;
		env->frctl.settings.max_iter += 2;
	}
	else if (keycode == 78 && env->frctl.settings.max_iter > 10) //-
	{
		env->frctl.settings.zoom_x /= 1.3;
		env->frctl.settings.zoom_y /= 1.3;
		env->frctl.settings.max_iter -= 2;
	}
	else if (keycode == 49)
	{
		env->draw(env);
		return (1);
	}
	else if (keycode == 9)
		f->color = 8;
	else if (keycode == 11)
		f->color = 0;
	else if (keycode == 15)
		f->color = 16;
	else if (keycode == 53)
		exit(0);
	fractals_compute(env);
	return (1);
}

int				mouse_motion(int x, int y, t_env *env)
{
	t_frctl	*f;

	f = &env->frctl;
	f->c_r = (double)x / WIN_WIDTH;
	f->c_i = (double)y / WIN_HEIGHT;
	fractals_compute(env);
	return (1);
}
