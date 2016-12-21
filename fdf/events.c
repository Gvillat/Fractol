/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:36:02 by gvillat           #+#    #+#             */
/*   Updated: 2016/06/02 11:36:06 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		translation(int keycode, ENV *env)
{
	if (keycode == 123)
		env->translate_x -= 5;
	if (keycode == 124)
		env->translate_x += 5;
	if (keycode == 126)
		env->translate_y += 5;
	if (keycode == 125)
		env->translate_y -= 5;
}

static void		zoom(int keycode, ENV *env)
{
	if (keycode == 78)
	{
		if (env->zoom > 1)
			env->zoom -= 5;
		else
			env->zoom = 1;
	}
	if (keycode == 69)
		env->zoom += 5;
}

static void		depth(int keycode, ENV *env)
{
	if (keycode == 2)
		env->depth += 1;
	if (keycode == 3)
		env->depth -= 1;
	iso_conversion(env);
}

int				key_binding(int keycode, ENV *env)
{
	int		i;

	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		i = -1;
		exit(0);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		translation(keycode, env);
	if (keycode == 78 || keycode == 69)
		zoom(keycode, env);
	if (keycode == 2 || keycode == 3)
		depth(keycode, env);
	mlx_clear_window(env->mlx, env->win);
	display_menu(env);
	tracing(env);
	return (0);
}
