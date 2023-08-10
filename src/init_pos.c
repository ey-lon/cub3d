/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:40:17 by abettini          #+#    #+#             */
/*   Updated: 2023/08/10 10:11:50 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_float(float *f1, float *f2, float v1, float v2)
{
	*f1 = v1;
	*f2 = v2;
}

int	ft_get_dir(char c, t_coord *coord)
{
	if (c == 'E')
	{
		ft_set_float(&coord->dir_x, &coord->dir_y, 0, 1);
		ft_set_float(&coord->plane_x, &coord->plane_y, 0.66, 0);
	}
	else if (c == 'W')
	{
		ft_set_float(&coord->dir_x, &coord->dir_y, 0, -1);
		ft_set_float(&coord->plane_x, &coord->plane_y, -0.66, 0);
	}
	else if (c == 'N')
	{
		ft_set_float(&coord->dir_x, &coord->dir_y, -1, 0);
		ft_set_float(&coord->plane_x, &coord->plane_y, 0, 0.66);
	}
	else if (c == 'S')
	{
		ft_set_float(&coord->dir_x, &coord->dir_y, 1, 0);
		ft_set_float(&coord->plane_x, &coord->plane_y, 0, -0.66);
	}
	else
		return (-1);
	return (0);
}

int	ft_get_pos_dir(t_coord *coord, char **mat)
{
	int	x;
	int	y;

	x = 0;
	while (mat[x])
	{
		y = 0;
		while (mat[x][y])
		{
			if (ft_strchr("NSWE", mat[x][y]))
			{
				coord->pos_x = x + 0.5;
				coord->pos_y = y + 0.5;
				ft_get_dir(mat[x][y], coord);
				return (0);
			}
			y += 1;
		}
		x += 1;
	}
	return (1);
}

void	ft_init_coord(t_game *game)
{
	ft_get_pos_dir(&game->coord, game->map);
	game->mh = ft_matlen(game->map);
	game->mw = ft_max_len(game->map);
}