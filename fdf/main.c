/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:37:42 by gvillat           #+#    #+#             */
/*   Updated: 2016/06/02 11:37:45 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_menu(ENV *env)
{
	mlx_string_put(env->mlx, env->win, 20, 20, 0x00BFA5,
		"fleche directionelle pour deplacer la camera");
	mlx_string_put(env->mlx, env->win, 20, 40, 0x00B8D4,
		"[+] et [-] sur le pave numerique pour zoomer");
	mlx_string_put(env->mlx, env->win, 20, 60, 0xCDDC39,
		"[d] et [f] pour gerer la hauteur");
	mlx_string_put(env->mlx, env->win, 20, 80, 0x0091EA,
		"ESC pour quitter");
}

void	init_img(ENV *env)
{
	if ((env->mlx = mlx_init()) == NULL)
		ft_error("mlx_init failed");
	if ((env->win = mlx_new_window(env->mlx,
		env->win_x, env->win_y, "FDF")) == NULL)
		ft_error("mlx_new_window failed");
}

int		main(int ac, char **av)
{
	ENV		*env;

	if (ac == 2)
	{
		if ((env = (ENV*)malloc(sizeof(ENV))) == NULL)
			ft_error("malloc failed");
		parsing(env, av[1]);
		tracing_initialize(env);
		init_img(env);
		iso_conversion(env);
		tracing(env);
		mlx_hook(env->win, 2, 1, &key_binding, env);
		display_menu(env);
		mlx_loop(env->mlx);
	}
	else if (ac > 2)
		ft_error("too much file arguments. Please precise only one file");
	else
		ft_error("not enough file arguments. Please precise only one file");
	return (0);
}
