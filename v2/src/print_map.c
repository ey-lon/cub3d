/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:55:52 by abettini          #+#    #+#             */
/*   Updated: 2023/08/24 15:11:36 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "cub3d.h"

void	ft_put_single_square(t_game *game, int mx, int my)
{
	int	x;
	int	y;

	y = 0;
	while (y < TS)
	{
		x = 0;
		while (x < TS)
		{
			mlx_pixel_put(game->mlx, game->win.ptr, \
				x + (TS * mx), y + (TS * my), 0xEE1010);
			x++;
		}
		y++;
	}
}

void	ft_put_squares(t_game *game)
{
	int		x;
	int		y;
	char	**mat;

	mat = game->map;
	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (mat[y][x] == '1')
			{
				ft_put_single_square(game, x, y);
			}
			x++;
		}
		y++;
	}
}

void	ft_put_ver_line(t_game *game, int mx)
{
	int		x;
	int		y;
	char	**mat;

	mat = game->map;
	x = mx * TS;
	y = 0;
	while (y <= (game->map_height * TS))
	{
		mlx_pixel_put(game->mlx, game->win.ptr, x, y, 0xFFFFFF);
		y++;
	}
}

void	ft_put_hor_line(t_game *game, int my)
{
	int		x;
	int		y;
	char	**mat;

	mat = game->map;
	y = my * TS;
	x = 0;
	while (x <= (game->map_width * TS))
	{
		mlx_pixel_put(game->mlx, game->win.ptr, x, y, 0xFFFFFF);
		x++;
	}
}

void	ft_put_lines(t_game *game)
{
	int		x;
	int		y;
	char	**mat;

	mat = game->map;
	x = 0;
	y = 0;
	while (x <= game->map_width)
	{
		ft_put_ver_line(game, x);
		x++;
	}
	while (y <= game->map_height)
	{
		ft_put_hor_line(game, y);
		y++;
	}
}

void	ft_print_map(t_game *game)
{
	ft_put_squares(game);
	ft_put_lines(game);
}
*/
