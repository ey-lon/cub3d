/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:46:27 by abettini          #+#    #+#             */
/*   Updated: 2023/08/28 17:30:27 by abettini         ###   ########.fr       */
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
