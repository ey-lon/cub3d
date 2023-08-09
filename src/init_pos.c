/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:40:17 by abettini          #+#    #+#             */
/*   Updated: 2023/08/09 11:32:42 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_dir(char c, t_coord *coord)
{
	if (c == 'N')
	{
		coord->dir_x = 0;
		coord->dir_y = 1;
		coord->plane_x = -0.66;
		coord->plane_y = 0;
	}
	else if (c == 'S')
	{
		coord->dir_x = 0;
		coord->dir_y = -1;
		coord->plane_x = 0.66;
		coord->plane_y = 0;
	}
	else if (c == 'W')
	{
		coord->dir_x = -1;
		coord->dir_y = 0;
		coord->plane_x = 0;
		coord->plane_y = 0.66;
	}
	else if (c == 'E')
	{
		coord->dir_x = 1;
		coord->dir_y = 0;
		coord->plane_x = 0;
		coord->plane_y = -0.66;
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
				coord->pos_x = x;
				coord->pos_y = y;
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
}