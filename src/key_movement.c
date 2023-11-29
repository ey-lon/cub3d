/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:35:20 by abettini          #+#    #+#             */
/*   Updated: 2023/11/29 10:01:14 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_move_up(t_game *game)
{
	int	x;
	int	y;

	x = (int)(game->coord.pos_x + game->coord.dir_x * SPEED_MOVE + \
		WALL_OFFSET * game->coord.dir_x);
	y = (int)(game->coord.pos_y);
	if (x >= 0 && x < game->map_height)
		if (game->map[x][y] != '1')
			game->coord.pos_x += game->coord.dir_x * SPEED_MOVE;
	x = (int)(game->coord.pos_x);
	y = (int)(game->coord.pos_y + game->coord.dir_y * SPEED_MOVE + \
		WALL_OFFSET * game->coord.dir_y);
	if (y >= 0 && y < game->map_width)
		if (game->map[x][y] != '1')
			game->coord.pos_y += game->coord.dir_y * SPEED_MOVE;
}

void	ft_key_move_down(t_game *game)
{
	int	x;
	int	y;

	x = (int)(game->coord.pos_x - game->coord.dir_x * SPEED_MOVE - \
		WALL_OFFSET * game->coord.dir_x);
	y = (int)(game->coord.pos_y);
	if (x >= 0 && x < game->map_height)
		if (game->map[x][y] != '1')
			game->coord.pos_x -= game->coord.dir_x * SPEED_MOVE;
	x = (int)(game->coord.pos_x);
	y = (int)(game->coord.pos_y - game->coord.dir_y * SPEED_MOVE - \
		WALL_OFFSET * game->coord.dir_y);
	if (y >= 0 && y < game->map_width)
		if (game->map[x][y] != '1')
			game->coord.pos_y -= game->coord.dir_y * SPEED_MOVE;
}

void	ft_key_move_left(t_game *game)
{
	int	x;
	int	y;

	x = (int)(game->coord.pos_x - game->coord.dir_y * SPEED_MOVE - \
		WALL_OFFSET * game->coord.dir_y);
	y = (int)(game->coord.pos_y);
	if (x >= 0 && x < game->map_height)
		if (game->map[x][y] != '1')
			game->coord.pos_x -= game->coord.dir_y * SPEED_MOVE;
	x = (int)(game->coord.pos_x);
	y = (int)(game->coord.pos_y + game->coord.dir_x * SPEED_MOVE + \
		WALL_OFFSET * game->coord.dir_x);
	if (y >= 0 && y < game->map_width)
		if (game->map[x][y] != '1')
			game->coord.pos_y += game->coord.dir_x * SPEED_MOVE;
}

void	ft_key_move_right(t_game *game)
{
	int	x;
	int	y;

	x = (int)(game->coord.pos_x + game->coord.dir_y * SPEED_MOVE + \
		WALL_OFFSET * game->coord.dir_y);
	y = (int)(game->coord.pos_y);
	if (x >= 0 && x < game->map_height)
		if (game->map[x][y] != '1')
			game->coord.pos_x += game->coord.dir_y * SPEED_MOVE;
	x = (int)(game->coord.pos_x);
	y = (int)(game->coord.pos_y - game->coord.dir_x * SPEED_MOVE - \
		WALL_OFFSET * game->coord.dir_x);
	if (y >= 0 && y < game->map_width)
		if (game->map[x][y] != '1')
			game->coord.pos_y -= game->coord.dir_x * SPEED_MOVE;
}
