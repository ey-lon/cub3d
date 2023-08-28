/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:55:56 by abettini          #+#    #+#             */
/*   Updated: 2023/08/28 17:34:08 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putsquare(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	max;
	int	offset;

	offset = 10;
	if (game->map_height > game->map_width)
		max = WIN_HEIGHT / (game->map_height * 4) + 1;
	else
		max = WIN_WIDTH / (game->map_width * 4) + 1;
	j = 0;
	while ((j < max) && (offset + (y * max * 2) + (j * 2) < WIN_HEIGHT))
	{
		i = 0;
		while ((i < max) && (offset + (x * max * 2) + (i * 2) < WIN_WIDTH))
		{
			ft_recolor_pixel(&game->bg, \
				offset + (x * max * 2) + (i * 2), \
				offset + (y * max * 2) + (j * 2), \
				color);
			i++;
		}
		j++;
	}
}

void	ft_minimap_base(t_game *game)
{
	int		y;
	int		x;
	char	**map;

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				ft_putsquare(game, x, y, BLUE);
			else if (map[y][x] == '0')
				ft_putsquare(game, x, y, WHITE);
			/* else if (map[y][x] == 'D')
				ft_putsquare(game, x, y, PURPLE);
			else if (map[y][x] == 'd')
				ft_putsquare(game, x, y, GREEN); */
			x++;
		}
		y++;
	}
}

void	ft_minimap_player(t_game *game)
{
	int	x;
	int	y;

	x = (int)game->coord.pos_y;
	y = (int)game->coord.pos_x;
	ft_putsquare(game, x, y, RED);
}

void	ft_minimap(t_game *game)
{
	if (game->minimap)
	{
		ft_minimap_base(game);
		ft_minimap_player(game);
	}
}
