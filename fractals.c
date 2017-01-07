#include "fractol.h"

void        fractals_compute(t_env *env)
{
	int		x;
	int		y;
	t_mdl	mdl;

	x = -1;
	mdl.x1 = -2.1;
	mdl.x2 = 0.6;
	mdl.y1 = -1.2;
	mdl.y2 = 1.2;
	mdl.settings.zoom_x = WIN_WIDTH / (mdl.x2 - mdl.x1);
	mdl.settings.zoom_y = WIN_HEIGHT / (mdl.y2 - mdl.y1);
	mdl.settings.max_iter = 50;
	while(++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			mandelbrot(x, y, &mdl, env);
		}
	}
}
