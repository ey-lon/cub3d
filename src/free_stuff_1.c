/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:26 by abettini          #+#    #+#             */
/*   Updated: 2023/07/27 17:46:17 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_imgs_paths(t_game *game)
{
	if (game->n.path)
		free(game->n.path);
	if (game->s.path)
		free(game->s.path);
	if (game->w.path)
		free(game->w.path);
	if (game->e.path)
		free(game->e.path);
}

/*
int	ft_free(char *str)
{
	if (str)
		free(str);
	return (0);
}
*/