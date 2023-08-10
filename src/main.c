/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:40:37 by abettini          #+#    #+#             */
/*   Updated: 2023/08/10 09:44:51 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_deal_key(int key, t_game *game);

void	*ft_new_window(t_game *game, int width, int height, char *name)
{
	void	*win;

	win = mlx_new_window(game->mlx, width, height, name);
	game->win.width = width;
	game->win.height = height;
	return (win);
}

int	ft_close(t_game *game)
{
	ft_free_game(game);
	exit(0);
}

int	ft_game(t_game *game)
{
	game->win.ptr=ft_new_window(game, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	ft_bg_img(game);
	mlx_hook(game->win.ptr, 17, 0, ft_close, game);
	mlx_hook(game->win.ptr, 2, 1L << 0, ft_deal_key, game);
	mlx_loop(game->mlx);
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
	game->e.ptr = 0;
	game->n.ptr = 0;
	game->s.ptr = 0;
	game->w.ptr = 0;
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
	ft_init_coord(&game);
	ft_game(&game);
	return (0);
}
