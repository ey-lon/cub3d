/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:40:37 by abettini          #+#    #+#             */
/*   Updated: 2024/04/11 12:13:22 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_game *game)
{
	ft_free_game(game);
	exit(0);
}

static void	*ft_new_window(t_game *game, int width, int height, char *name)
{
	void	*win;

	win = mlx_new_window(game->mlx, width, height, name);
	game->win.width = width;
	game->win.height = height;
	return (win);
}

static int	ft_game(t_game *game)
{
	game->win.ptr = ft_new_window(game, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	game->bg.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->bg.addr = mlx_get_data_addr(game->bg.img, \
		&game->bg.bits_per_pixel, &game->bg.line_length, &game->bg.endian);
	mlx_hook(game->win.ptr, 17, 0, ft_close, game);
	mlx_hook(game->win.ptr, 2, 1L << 0, ft_deal_key, game);
	mlx_hook(game->win.ptr, 3, 1L << 1, ft_release_key, game);
	mlx_loop_hook(game->mlx, ft_loop, game);
	mlx_loop(game->mlx);
	return (0);
}

static void	ft_info_init(t_game *game)
{
	game->mlx = mlx_init();
	game->map = NULL;
	game->bg.path = NULL;
	game->bg.height = WIN_HEIGHT;
	game->bg.width = WIN_WIDTH;
	game->n.path = NULL;
	game->s.path = NULL;
	game->w.path = NULL;
	game->e.path = NULL;
	game->e.img = NULL;
	game->n.img = NULL;
	game->s.img = NULL;
	game->w.img = NULL;
	game->floor = -1;
	game->ceiling = -1;
	game->keys_pressed = 0;
	game->minimap = 0;
	game->event = 1;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_dprintf(2, "Invalid number of arguments.\n") * 0 + 1);
	ft_info_init(&game);
	if (ft_get_info(&game, av[1]))
		return (1);
	ft_init_coord(&game);
	ft_game(&game);
	return (0);
}
