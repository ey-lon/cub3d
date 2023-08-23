/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:35:20 by abettini          #+#    #+#             */
/*   Updated: 2023/08/23 15:56:20 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_move_up(t_game *game)
{
	int	x;
	int	y;

	x = (int)(game->coord.pos_x + game->coord.dir_x * SPEED_MOVE);
	y = (int)(game->coord.pos_y);
	if (x >= 0 && x < game->mh)
		if (game->map[x][y] != '1')
			game->coord.pos_x += game->coord.dir_x * SPEED_MOVE;
	x = (int)(game->coord.pos_x);
	y = (int)(game->coord.pos_y + game->coord.dir_y * SPEED_MOVE);
	if (y >= 0 && y < game->mw)
		if (game->map[x][y] != '1')
			game->coord.pos_y += game->coord.dir_y * SPEED_MOVE;
}

void	ft_key_move_down(t_game *game)
{
	int	x;
	int	y;

	x = (int)(game->coord.pos_x - game->coord.dir_x * SPEED_MOVE);
	y = (int)(game->coord.pos_y);
	if (x >= 0 && x < game->mh)
		if (game->map[x][y] != '1')
			game->coord.pos_x -= game->coord.dir_x * SPEED_MOVE;
	x = (int)(game->coord.pos_x);
	y = (int)(game->coord.pos_y - game->coord.dir_y * SPEED_MOVE);
	if (y >= 0 && y < game->mw)
		if (game->map[x][y] != '1')
			game->coord.pos_y -= game->coord.dir_y * SPEED_MOVE;
}

void	ft_key_move_left(t_game *game)
{
	int	x;
	int	y;

	x = (int)(game->coord.pos_x - game->coord.dir_y * SPEED_MOVE);
	y = (int)(game->coord.pos_y);
	if (x >= 0 && x < game->mh)
		if (game->map[x][y] != '1')
			game->coord.pos_x -= game->coord.dir_y * SPEED_MOVE;
	x = (int)(game->coord.pos_x);
	y = (int)(game->coord.pos_y + game->coord.dir_x * SPEED_MOVE);
	if (y >= 0 && y < game->mw)
		if (game->map[x][y] != '1')
			game->coord.pos_y += game->coord.dir_x * SPEED_MOVE;
}

void	ft_key_move_right(t_game *game)
{
	int	x;
	int	y;

	x = (int)(game->coord.pos_x + game->coord.dir_y * SPEED_MOVE);
	y = (int)(game->coord.pos_y);
	if (x >= 0 && x < game->mh)
		if (game->map[x][y] != '1')
			game->coord.pos_x += game->coord.dir_y * SPEED_MOVE;
	x = (int)(game->coord.pos_x);
	y = (int)(game->coord.pos_y - game->coord.dir_x * SPEED_MOVE);
	if (y >= 0 && y < game->mw)
		if (game->map[x][y] != '1')
			game->coord.pos_y -= game->coord.dir_x * SPEED_MOVE;
}
