/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:27:34 by abettini          #+#    #+#             */
/*   Updated: 2023/08/09 11:49:31 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_game *game);

void	ft_draw_ver_line(t_game *game, int y_start, int y_end, int x, int color)
{
	while (y_start <= y_end)
	{
		mlx_pixel_put(game->mlx, game->win.ptr, x, y_start, color);
		y_start++;
	}
}

void	ft_view(t_game *game)
{
	int		x;
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;
	float	delta_dist_x;
	float	delta_dist_y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_dir_x = game->coord.dir_x + game->coord.plane_x * camera_x;
		ray_dir_y = game->coord.dir_y + game->coord.plane_y * camera_x;
		
		//which box of the map we're in
		int map_x = game->coord.pos_x;
		int map_y = game->coord.pos_y;

		//length of ray from current position to next x or y-side
		double side_dist_x;
		double side_dist_y;
		//length of ray from one x or y-side to next x or y-side
		if (ray_dir_x)
			delta_dist_x = fabs(1 / ray_dir_x);
		else
			delta_dist_x = (float)INT_MAX;
		if (ray_dir_y)
			delta_dist_y = fabs(1 / ray_dir_y);
		else
			delta_dist_y = (float)INT_MAX;

		double perp_wall_dist;

		//what direction to step in x or y-direction (either +1 or -1)
		int step_x;
		int step_y;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->coord.pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->coord.pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->coord.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->coord.pos_y) * delta_dist_y;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall
			if (game->map[map_x][map_y] == '1')
				hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if(side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(WIN_HEIGHT / perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if(drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

		int col = BLUE;
		if (side)
			col /= 2;

		ft_draw_ver_line(game, drawStart, drawEnd, x, col);

		x++;
	}
}

int	ft_deal_key(int key, t_game *game)
{
	mlx_clear_window(game->mlx, game->win.ptr);
	//printf("%f %f %f %f %f %f\n", game->coord.pos_x, game->coord.pos_y, game->coord.dir_x, game->coord.dir_y, SPEED_MOVE, SPEED_ROT);
	if (key == ESC)
		ft_close(game);
	if (key == KEY_W)
	{
		if (game->map[(int)(game->coord.pos_x + game->coord.dir_x * SPEED_MOVE)][(int)(game->coord.pos_y)] == '0')
			game->coord.pos_x += game->coord.dir_x * SPEED_MOVE;
		if (game->map[(int)(game->coord.pos_x)][(int)(game->coord.pos_y + game->coord.dir_y * SPEED_MOVE)] == '0')
			game->coord.pos_y += game->coord.dir_y * SPEED_MOVE;
	}
	//move backwards if no wall behind you
	else if (key == KEY_S)
	{
		if (game->map[(int)(game->coord.pos_x - game->coord.dir_x * SPEED_MOVE)][(int)(game->coord.pos_y)] == '0')
			game->coord.pos_x -= game->coord.dir_x * SPEED_MOVE;
		if (game->map[(int)(game->coord.pos_x)][(int)(game->coord.pos_y - game->coord.dir_y * SPEED_MOVE)] == '0')
			game->coord.pos_y -= game->coord.dir_y * SPEED_MOVE;
	}
	//rotate to the right
	else if (key == ARR_RIGHT)
	{
		//both camera direction and camera plane must be rotated
		game->coord.old_dir_x = game->coord.dir_x;
		game->coord.dir_x = game->coord.dir_x * cos(-SPEED_ROT) - game->coord.dir_y * sin(-SPEED_ROT);
		game->coord.dir_y = game->coord.old_dir_x * sin(-SPEED_ROT) + game->coord.dir_y * cos(-SPEED_ROT);
		game->coord.old_plane_x = game->coord.plane_x;
		game->coord.plane_x = game->coord.plane_x * cos(-SPEED_ROT) - game->coord.plane_y * sin(-SPEED_ROT);
		game->coord.plane_y = game->coord.old_plane_x * sin(-SPEED_ROT) + game->coord.plane_y * cos(-SPEED_ROT);
	}
	//rotate to the left
	else if (key == ARR_LEFT)
	{
		//both camera direction and camera plane must be rotated
		game->coord.old_dir_x = game->coord.dir_x;
		game->coord.dir_x = game->coord.dir_x * cos(SPEED_ROT) - game->coord.dir_y * sin(SPEED_ROT);
		game->coord.dir_y = game->coord.old_dir_x * sin(SPEED_ROT) + game->coord.dir_y * cos(SPEED_ROT);
		game->coord.old_plane_x = game->coord.plane_x;
		game->coord.plane_x = game->coord.plane_x * cos(SPEED_ROT) - game->coord.plane_y * sin(SPEED_ROT);
		game->coord.plane_y = game->coord.old_plane_x * sin(SPEED_ROT) + game->coord.plane_y * cos(SPEED_ROT);
	}
	ft_view(game);
	//ft_print_map(game);
	return (0);
}