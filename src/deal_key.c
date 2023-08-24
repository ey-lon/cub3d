/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:27:34 by abettini          #+#    #+#             */
/*   Updated: 2023/08/24 14:52:31 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_game *game);

int	ft_deal_key(int key, t_game *game)
{
	int	check;

	check = 1;
	if (key == ESC)
		ft_close(game);
	else if (key == KEY_W || key == ARR_UP)
		check = ft_key_move_up(game);
	else if (key == KEY_S || key == ARR_DOWN)
		check = ft_key_move_down(game);
	else if (key == KEY_A)
		check = ft_key_move_left(game);
	else if (key == KEY_D)
		check = ft_key_move_right(game);
	else if (key == ARR_LEFT)
		ft_key_rotate_left(game);
	else if (key == ARR_RIGHT)
		ft_key_rotate_right(game);
	else
		check = 0;
	if (check)
		ft_new_bg(game);
	return (0);
}

//ft_print_map(game);