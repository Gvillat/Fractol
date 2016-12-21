/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:38:16 by gvillat           #+#    #+#             */
/*   Updated: 2016/06/02 11:38:22 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		getting_size(ENV *env, int fd)
{
	char	**tmp;
	char	*line;
	int		gnl;
	int		i;

	env->l_nbr = 0;
	env->c_nbr = 0;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (env->l_nbr == 0)
		{
			i = 0;
			tmp = ft_strsplit(line, ' ');
			while (tmp[i] != NULL)
			{
				env->c_nbr++;
				i++;
			}
			free(tmp);
		}
		env->l_nbr++;
	}
}

static void		getting_nectar(ENV *env, char *tmp, int i, int j)
{
	long		nectar;
	char		**tmp2;

	tmp2 = NULL;
	if (ft_strrchr(tmp, ','))
	{
		tmp2 = ft_strsplit(tmp, ',');
		nectar = ft_atoi(tmp2[0]);
		env->map[i][j].color = tmp2[1];
	}
	else
	{
		nectar = ft_atoi(tmp);
		env->map[i][j].color = "0x00FF00";
	}
	if (nectar < INT_MIN || nectar > INT_MAX)
		ft_error("wrong file format, please use only integers for depth");
	env->map[i][j].z = (int)nectar;
	env->map[i][j].x_init = env->map[i][j].x;
	env->map[i][j].y_init = env->map[i][j].y;
}

static void		getting_content(ENV *env, int fd)
{
	char	**tmp;
	char	*line;
	int		i;
	int		j;

	i = -1;
	if ((env->map = (PXL**)malloc(sizeof(PXL*) * env->l_nbr)) == NULL)
		ft_error(NULL);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		if ((env->map[++i] = (PXL*)malloc(sizeof(PXL) * env->c_nbr)) == NULL)
			ft_error(NULL);
		j = -1;
		while (tmp[++j] != NULL)
		{
			env->map[i][j].x = j + 1;
			env->map[i][j].y = i + 1;
			getting_nectar(env, tmp[j], i, j);
		}
		if (j != env->c_nbr)
			ft_error("wrong file format");
	}
}

void			parsing(ENV *env, char *av)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error("couldn't open file.");
	getting_size(env, fd);
	close(fd);
	if (env->l_nbr == 0 || env->c_nbr == 0)
		ft_error("nothing to display, your file is empty");
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error("couldn't open file.");
	getting_content(env, fd);
	if (close(fd) != 0)
		ft_error(NULL);
}
