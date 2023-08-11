/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_xpm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:26:09 by abettini          #+#    #+#             */
/*   Updated: 2023/08/11 14:20:50 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_get_single_img_xpm(void *mlx, t_data *data)
{
	return (mlx_xpm_file_to_image(mlx, data->path, &data->width, &data->height));
}

void	ft_get_imgs_xpm(t_game *game)
{
	game->n.img = ft_get_single_img_xpm(game->mlx, &(game->n));
	game->s.img = ft_get_single_img_xpm(game->mlx, &(game->s));
	game->w.img = ft_get_single_img_xpm(game->mlx, &(game->w));
	game->e.img = ft_get_single_img_xpm(game->mlx, &(game->e));
}
