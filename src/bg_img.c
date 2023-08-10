/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:46:27 by abettini          #+#    #+#             */
/*   Updated: 2023/08/10 09:39:59 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_color_half_area(void *mlx, t_data *data, int start_y, int max_y, int color)
{
	char	*dst;
	int 	x;
	int		y;
	int		pixel;

	if (data->bits_per_pixel != 32)
    	color = mlx_get_color_value(mlx, color);

	y = start_y;
	while (y < max_y)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel = (y * data->line_length) + (x * 4);

			if (data->endian == 1)
			{
				data->addr[pixel + 0] = (color >> 24);
				data->addr[pixel + 1] = (color >> 16) & 0xFF;
				data->addr[pixel + 2] = (color >> 8) & 0xFF;
				data->addr[pixel + 3] = (color) & 0xFF;
			}
			else if (data->endian == 0)
			{
				data->addr[pixel + 0] = (color) & 0xFF;
				data->addr[pixel + 1] = (color >> 8) & 0xFF;
				data->addr[pixel + 2] = (color >> 16) & 0xFF;
				data->addr[pixel + 3] = (color >> 24);
			}
			x++;
		}
		y++;
	}
}

void	ft_bg_img(t_game *game)
{
	game->bg.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->bg.addr = mlx_get_data_addr(game->bg.img, &game->bg.bits_per_pixel, &game->bg.line_length, &game->bg.endian);
	ft_color_half_area(game->mlx, &game->bg, 0, WIN_HEIGHT / 2, game->floor);
	ft_color_half_area(game->mlx, &game->bg, WIN_HEIGHT / 2, WIN_HEIGHT, game->ceiling);
	mlx_put_image_to_window(game->mlx, game->win.ptr, game->bg.img, 0, 0);
}
