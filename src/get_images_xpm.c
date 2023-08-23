/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_xpm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:26:09 by abettini          #+#    #+#             */
/*   Updated: 2023/08/23 09:50:14 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_get_single_img_xpm(void *mlx, t_data *data)
{
	return (mlx_xpm_file_to_image(mlx, data->path, \
		&data->width, &data->height));
}

void	ft_get_imgs_xpm(t_game *game)
{
	game->n.img = ft_get_single_img_xpm(game->mlx, &(game->n));
	game->s.img = ft_get_single_img_xpm(game->mlx, &(game->s));
	game->w.img = ft_get_single_img_xpm(game->mlx, &(game->w));
	game->e.img = ft_get_single_img_xpm(game->mlx, &(game->e));
	game->n.addr = mlx_get_data_addr(game->n.img, \
		&game->n.bits_per_pixel, &game->n.line_length, &game->n.endian);
	game->s.addr = mlx_get_data_addr(game->s.img, \
		&game->s.bits_per_pixel, &game->s.line_length, &game->s.endian);
	game->w.addr = mlx_get_data_addr(game->w.img, \
		&game->w.bits_per_pixel, &game->w.line_length, &game->w.endian);
	game->e.addr = mlx_get_data_addr(game->e.img, \
		&game->e.bits_per_pixel, &game->e.line_length, &game->e.endian);
}
