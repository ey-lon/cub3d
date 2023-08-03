/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:27:34 by abettini          #+#    #+#             */
/*   Updated: 2023/08/03 11:45:23 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_game *game);

void	ft_draw_ray(t_game *game, int rx, int ry)
{
	float it;
	int	x;

	it = 0;
	while (1)
	{
		x = (int)(game->pos.px + game->pos.pdx * it);
		if (x == rx || x < 0)
			break ;
		mlx_pixel_put(game->mlx, game->win.ptr, game->pos.px + game->pos.pdx * it, game->pos.py + game->pos.pdy * it, LIGHT_BLUE);
		it += 0.1;
	}
	mlx_pixel_put(game->mlx, game->win.ptr, game->pos.px, game->pos.py, YELLOW);
}

void	ft_ray(t_game *game)
{
	float	atan;
	float	ntan;
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	int		mx;
	int		my;
	int		dof;
	
	//---HORIZONTAL LINES---
	atan = -1 / tan(game->pos.pa);
	if (game->pos.pa == 0 || game->pos.pa == PI)
	{
		rx = game->mw * TS - 1;
		ry = game->mh * TS - 1;
		dof = game->mh;
	}
	else if (game->pos.pa > PI)
	{
		ry = ((int)game->pos.py / TS) * TS;
		rx = (game->pos.py - ry) * atan + game->pos.px;
		yo = TS * -1;
		xo = -yo * atan;
	}
	else if (game->pos.pa < PI)
	{
		ry = (((int)game->pos.py / TS) * TS) + TS;
		rx = (game->pos.py - ry) * atan + game->pos.px;
		yo = TS;
		xo = -yo * atan;
	}
	dof = 0;
	while (dof < game->mh)
	{
		mx = (int)rx / TS;
		my = (int)ry / TS;
		if ((mx > game->mw - 1 || my > game->mh - 1 || mx < 0 || my < 0) || game->map[my][mx] == '1')
			break ;
		else
		{
			rx += xo;
			ry += yo;
			dof += 1;
		}
	}
	if (rx < 0)
		rx = 0;
	else if (rx > game->mw * TS - 1)
		rx = game->mw * TS - 1;
	if (ry < 0)
		ry = 0;
	else if (rx > game->mh * TS - 1)
		ry = game->mh * TS - 1;

	/* //---VERTICAL LINES---
	ntan = -tan(game->pos.pa);
	if (game->pos.pa == 0 || game->pos.pa == PI)
	{
		rx = game->pos.px;
		ry = game->pos.py;
		dof = game->mh;
	}
	else if (game->pos.pa > (PI / 2) && game->pos.pa < (PI + PI / 2))
	{
		rx = ((int)game->pos.px / TS) * TS;
		ry = (game->pos.px - rx) * ntan + game->pos.py;
		xo = TS * -1;
		yo = -xo * ntan;
	}
	else if (game->pos.pa < (PI / 2) || game->pos.pa > (PI + PI / 2))
	{
		rx = (((int)game->pos.px / TS) * TS) + TS;
		ry = (game->pos.px - rx) * ntan + game->pos.py;
		xo = TS;
		yo = -yo * ntan;
	}
	dof = 0;
	while (dof < game->mw)
	{
		mx = (int)rx / TS;
		my = (int)ry / TS;
		if ((mx > game->mw - 1 || my > game->mh - 1 || mx < 0 || my < 0) || game->map[my][mx] == '1')
			break ;
		else
		{
			rx += xo;
			ry += yo;
			dof += 1;
		}
	}
	if (rx < 0)
		rx = 0;
	else if (rx > game->mw * TS - 1)
		rx = game->mw * TS - 1;
	if (ry < 0)
		ry = 0;
	else if (rx > game->mh * TS - 1)
		ry = game->mh * TS - 1;
	*/
	//----------------------------------------------

	ft_draw_ray(game, rx, ry);
}

int	ft_deal_key(int key, t_game *game)
{
	if (key == ESC)
		ft_close(game);
	mlx_clear_window(game->mlx, game->win.ptr);
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
	ft_ray(game);
	return (0);
}