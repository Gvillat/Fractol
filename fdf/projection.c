/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:38:34 by gvillat           #+#    #+#             */
/*   Updated: 2016/06/02 11:38:39 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			iso_conversion(ENV *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->l_nbr)
	{
		j = 0;
		while (j < env->c_nbr)
		{
			env->map[i][j].x = sqrt(2) / 2 * (env->map[i][j].x_init -
				env->map[i][j].y_init);
			env->map[i][j].y = -(((sqrt(2) / env->depth) * env->map[i][j].z)
				- (1 / sqrt(6)) * (env->map[i][j].x_init +
				env->map[i][j].y_init));
			j++;
		}
		i++;
	}
}
