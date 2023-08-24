/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:27:34 by abettini          #+#    #+#             */
/*   Updated: 2023/08/24 17:19:00 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_game *game);

int	ft_deal_key(int key, t_game *game)
{
	if (key == ESC)
		ft_close(game);
	else if (key == KEY_W)
		game->keys_pressed |= UP_P;
	else if (key == KEY_S)
		game->keys_pressed |= DOWN_P;
	else if (key == KEY_A)
		game->keys_pressed |= LEFT_P;
	else if (key == KEY_D)
		game->keys_pressed |= RIGHT_P;
	else if (key == ARR_LEFT)
		game->keys_pressed |= ROT_L_P;
	else if (key == ARR_RIGHT)
		game->keys_pressed |= ROT_R_P;
	return (0);
}

int	ft_release_key(int key, t_game *game)
{
	if (key == KEY_W)
		game->keys_pressed ^= UP_P;
	else if (key == KEY_S)
		game->keys_pressed ^= DOWN_P;
	else if (key == KEY_A)
		game->keys_pressed ^= LEFT_P;
	else if (key == KEY_D)
		game->keys_pressed ^= RIGHT_P;
	else if (key == ARR_LEFT)
		game->keys_pressed ^= ROT_L_P;
	else if (key == ARR_RIGHT)
		game->keys_pressed ^= ROT_R_P;
	return (0);
}

void	ft_loop(t_game *game)
{
	if (game->keys_pressed & UP_P)
		ft_key_move_up(game);
	if (game->keys_pressed & DOWN_P)
		ft_key_move_down(game);
	if (game->keys_pressed & LEFT_P)
		ft_key_move_left(game);
	if (game->keys_pressed & RIGHT_P)
		ft_key_move_right(game);
	if (game->keys_pressed & ROT_L_P)
		ft_key_rotate_left(game);
	if (game->keys_pressed & ROT_R_P)
		ft_key_rotate_right(game);
	ft_new_bg(game);
}
