/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:40:37 by abettini          #+#    #+#             */
/*   Updated: 2023/07/27 17:58:53 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_game(char *path)
{
	return (0);
}

void	ft_info_init(t_game *game)
{
	game->mlx = mlx_init();
	game->map = NULL;
	game->n.path = 0;
	game->s.path = 0;
	game->w.path = 0;
	game->e.path = 0;
	game->e.img = 0;
	game->n.img = 0;
	game->s.img = 0;
	game->w.img = 0;
	game->floor = -1;
	game->ceiling = -1;
}

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return (ft_dprintf(2, "Invalid number of arguments.\n") * 0 + 1);

	ft_info_init(&game);

	if (ft_get_info(&game, av[1]))
		return (1);

	ft_game(av[1]);
	return (0);
}
