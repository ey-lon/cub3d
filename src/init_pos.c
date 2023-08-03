/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:40:17 by abettini          #+#    #+#             */
/*   Updated: 2023/08/02 10:32:31 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_get_pa(char **mat)
{
	int	x;
	int	y;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (mat[y][x] == 'N')
				return (PI + PI / 2);
			if (mat[y][x] == 'S')
				return (PI / 2);
			if (mat[y][x] == 'W')
				return (PI);
			if (mat[y][x] == 'E')
				return (0);
			x += 1;
		}
		y += 1;
	}
	return (-1);
}

int	ft_get_px_py(char **mat, float *mx, float *my)
{
	int	x;
	int	y;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (ft_strchr("NSWE", mat[y][x]))
			{
				*mx = x * TS + TS / 2;
				*my = y * TS + TS / 2;
				return (0);
			}
			x += 1;
		}
		y += 1;
	}
	return (1);
}

void	ft_init_pos(t_game *game)
{
	game->pos.pa = ft_get_pa(game->map);
	game->pos.pdx = cos(game->pos.pa) * 5;
	game->pos.pdy = sin(game->pos.pa) * 5;
	ft_get_px_py(game->map, &game->pos.px, &game->pos.py);
}