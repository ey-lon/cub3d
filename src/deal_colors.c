/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:46:27 by abettini          #+#    #+#             */
/*   Updated: 2023/11/29 11:29:46 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//-----------------------------------------------------------
//COLORS

int	ft_get_pixel_color(t_data *data, int x, int y)
{
	char	*pixel;

	pixel = data->addr + ((y * data->line_length) + \
				(x * (data->bits_per_pixel / 8)));
	return (*(int *)pixel);
}

void	ft_set_pixel_color(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + \
		(y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)pixel = color;
}

//-----------------------------------------------------------
//BACKGROUND

void	ft_new_bg(t_game *game)
{
	ft_raycasting(game);
	ft_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win.ptr, game->bg.img, 0, 0);
}
