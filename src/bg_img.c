/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:46:27 by abettini          #+#    #+#             */
/*   Updated: 2023/08/14 10:13:18 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_color_area(t_data *data, int start_y, int max_y, int color)
{
	int		x;
	int		y;
	char	*pixel;

	y = start_y;
	while (y < max_y)
	{
		x = 0;
		while (x < data->width)
		{
			pixel = data->addr + \
				(y * data->line_length + x * (data->bits_per_pixel / 8));
			*(int *)pixel = color;
			x++;
		}
		y++;
	}
}

void	ft_bg_img(t_game *game)
{
	game->bg.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->bg.addr = mlx_get_data_addr(game->bg.img, \
		&game->bg.bits_per_pixel, &game->bg.line_length, &game->bg.endian);
	ft_color_area(&game->bg, \
		0, game->bg.height / 2, game->floor);
	ft_color_area(&game->bg, \
		game->bg.height / 2, game->bg.height, game->ceiling);
	mlx_put_image_to_window(game->mlx, game->win.ptr, game->bg.img, 0, 0);
}
