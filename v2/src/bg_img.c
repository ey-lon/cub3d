/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:46:27 by abettini          #+#    #+#             */
/*   Updated: 2023/08/24 15:21:46 by abettini         ###   ########.fr       */
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

void	ft_recolor_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + \
		(y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	ft_color_area(t_data *data, int start_y, int max_y, int color)
{
	int		x;
	int		y;

	y = start_y;
	while (y < max_y)
	{
		x = 0;
		while (x < data->width)
		{
			ft_recolor_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

//-----------------------------------------------------------
//BACKGROUND

void	ft_reset_bg(t_game *game)
{
	ft_color_area(&game->bg, \
		0, game->bg.height / 2, game->ceiling);
	ft_color_area(&game->bg, \
		game->bg.height / 2, game->bg.height, game->floor);
}

void	ft_new_bg(t_game *game)
{
	game->bg.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->bg.addr = mlx_get_data_addr(game->bg.img, \
		&game->bg.bits_per_pixel, &game->bg.line_length, &game->bg.endian);
	ft_reset_bg(game);
	ft_raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win.ptr, game->bg.img, 0, 0);
	mlx_destroy_image(game->mlx, game->bg.img);
}
