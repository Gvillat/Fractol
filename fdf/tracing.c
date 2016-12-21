/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:38:52 by gvillat           #+#    #+#             */
/*   Updated: 2016/06/02 11:38:56 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		tracing_display(ENV *env, int x, int y)
{
	env->dx = abs(env->x2 - env->x1);
	env->dy = abs(env->y2 - env->y1);
	env->sx = (env->x1 < env->x2 ? 1 : -1);
	env->sy = (env->y1 < env->y2 ? 1 : -1);
	env->err = (env->dx > env->dy ? env->dx : -(env->dy)) / 2;
	while (!(env->x1 == env->x2 && env->y1 == env->y2))
	{
		mlx_pixel_put(env->mlx, env->win, env->x1, env->y1,
			strtol(env->map[y][x].color, NULL, 16));
		env->e2 = env->err;
		if (env->e2 > -(env->dx))
		{
			env->err -= env->dy;
			env->x1 += env->sx;
		}
		if (env->e2 < env->dy)
		{
			env->err += env->dx;
			env->y1 += env->sy;
		}
	}
}

static void		tracing_lines(ENV *env, int x, int y)
{
	env->x1 = env->map[y][x].x * env->zoom + env->translate_x;
	env->y1 = env->map[y][x].y * env->zoom + env->translate_y;
	env->x2 = env->map[y][x + 1].x * env->zoom + env->translate_x;
	env->y2 = env->map[y][x + 1].y * env->zoom + env->translate_y;
	tracing_display(env, x, y);
}

static void		tracing_columns(ENV *env, int x, int y)
{
	env->x1 = env->map[y][x].x * env->zoom + env->translate_x;
	env->y1 = env->map[y][x].y * env->zoom + env->translate_y;
	env->x2 = env->map[y + 1][x].x * env->zoom + env->translate_x;
	env->y2 = env->map[y + 1][x].y * env->zoom + env->translate_y;
	tracing_display(env, x, y);
}

void			tracing_initialize(ENV *env)
{
	int		x_max;
	int		y_max;

	env->zoom = 1;
	env->depth = 25;
	env->win_x = 1280;
	env->win_y = 1024;
	env->translate_x = env->win_x / 2;
	env->translate_y = env->win_y / 4;
	x_max = env->map[env->l_nbr - 1][env->c_nbr - 1].x;
	y_max = env->map[env->l_nbr - 1][env->c_nbr - 1].y;
	while ((x_max * env->zoom + env->translate_x)
			< (env->win_x - (env->win_x / 4))
			&& (y_max * env->zoom + env->translate_x)
			< (env->win_y - (env->win_y / 5)))
		env->zoom += 1;
}

void			tracing(ENV *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->l_nbr)
	{
		x = 0;
		while (x < env->c_nbr - 1)
		{
			if (y < env->l_nbr - 1)
			{
				tracing_lines(env, x, y);
				tracing_columns(env, x, y);
			}
			else
				tracing_lines(env, x, y);
			x++;
		}
		if (y < env->l_nbr - 1)
			tracing_columns(env, x, y);
		y++;
	}
}
