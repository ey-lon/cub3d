/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:40:37 by abettini          #+#    #+#             */
/*   Updated: 2023/08/01 11:47:06 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_print_guy(t_game *game, int color)
{
	float it;

	it = 0.1;
	while (it < 4.0)
	{
		mlx_pixel_put(game->mlx, game->win.ptr, game->pos.px + game->pos.pdx * it, game->pos.py + game->pos.pdy * it, color);
		it += 0.1;
	}
	if (color == BLACK)
		mlx_pixel_put(game->mlx, game->win.ptr, game->pos.px, game->pos.py, color);
	else
		mlx_pixel_put(game->mlx, game->win.ptr, game->pos.px, game->pos.py, YELLOW);
}

int	ft_deal_key(int key, t_game *game)
{
	if (key == ESC)
		ft_close(game);
	ft_print_guy(game, BLACK);
	if (key == KEY_W)
	{
		game->pos.px += game->pos.pdx;
		game->pos.py += game->pos.pdy;
	}
	else if (key == KEY_S)
	{
		game->pos.px -= game->pos.pdx;
		game->pos.py -= game->pos.pdy;
	}
	else if (key == KEY_A)
	{
		game->pos.px += game->pos.pdy;
		game->pos.py -= game->pos.pdx;
	}
	else if (key == KEY_D)
	{
		game->pos.px -= game->pos.pdy;
		game->pos.py += game->pos.pdx;
	}
	else if (key == ARR_LEFT)
	{
		game->pos.pa -= 0.1;
		if (game->pos.pa < 0)
			game->pos.pa += 2 * PI;
		game->pos.pdx = cos(game->pos.pa) * 5;
		game->pos.pdy = sin(game->pos.pa) * 5;
	}
	else if (key == ARR_RIGHT)
	{
		game->pos.pa += 0.1;
		if (game->pos.pa >= 2 * PI)
			game->pos.pa -= 2 * PI;
		game->pos.pdx = cos(game->pos.pa) * 5;
		game->pos.pdy = sin(game->pos.pa) * 5;
	}
	ft_print_map(game);
	ft_print_guy(game, 0x9999FF);
	return (0);
}

int	ft_game(t_game *game)
{
	game->win.ptr=ft_new_window(game, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
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
	ft_init_pos(&game);
	game.mh = ft_matlen(game.map);
	game.mw = ft_max_len(game.map);
	ft_game(&game);
	return (0);
}
