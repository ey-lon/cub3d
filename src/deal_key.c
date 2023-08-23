/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:27:34 by abettini          #+#    #+#             */
/*   Updated: 2023/08/23 09:52:15 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_game *game);

void	ft_reset_bg(t_game *game);

void	ft_view(t_game *game);

int	ft_deal_key(int key, t_game *game)
{
	if (key == ESC)
		ft_close(game);
	else if (key == KEY_W || key == ARR_UP)
		ft_key_move_up(game);
	else if (key == KEY_S || key == ARR_DOWN)
		ft_key_move_down(game);
	else if (key == KEY_A)
		ft_key_move_left(game);
	else if (key == KEY_D)
		ft_key_move_right(game);
	else if (key == ARR_LEFT)
		ft_key_rotate_left(game);
	else if (key == ARR_RIGHT)
		ft_key_rotate_right(game);
	else
		return (1);
	ft_reset_bg(game);
	ft_view(game);
	mlx_put_image_to_window(game->mlx, game->win.ptr, game->bg.img, 0, 0);
	//ft_print_map(game);
	return (0);
}
