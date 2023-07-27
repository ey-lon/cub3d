/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:26 by abettini          #+#    #+#             */
/*   Updated: 2023/07/27 17:30:04 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_imgs_paths(t_game *game)
{
	free(game->n.path);
	free(game->s.path);
	free(game->w.path);
	free(game->e.path);
}

/*
int	ft_free(char *str)
{
	free(str);
	return (0);
}
*/