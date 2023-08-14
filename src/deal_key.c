/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:27:34 by abettini          #+#    #+#             */
/*   Updated: 2023/08/14 14:57:53 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_game *game);

void ft_recolor_line(t_data *data, int y_start, int y_end, int x, int color)
{
	char	*pixel;

	while (y_start <= y_end)
	{
		pixel = data->addr + (y_start * data->line_length + x * (data->bits_per_pixel / 8));
		*(int *)pixel = color;
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
	double	side_dist_x;
	double	side_dist_y;
	int 	map_x;
	int		map_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;

	x = 0;
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_dir_x = game->coord.dir_x + game->coord.plane_x * camera_x;
		ray_dir_y = game->coord.dir_y + game->coord.plane_y * camera_x;
		
		//which box of the map we're in
		map_x = game->coord.pos_x;
		map_y = game->coord.pos_y;

		if (ray_dir_x)
			delta_dist_x = fabs(1 / ray_dir_x);
		else
			delta_dist_x = (float)INT_MAX;
		if (ray_dir_y)
			delta_dist_y = fabs(1 / ray_dir_y);
		else
			delta_dist_y = (float)INT_MAX;

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

		//---CHECK FOR WALLS---
		hit = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 2 + step_x;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1 + step_y;
			}
			if (game->map[map_x][map_y] == '1')
				hit = 1;
		}
		if (side % 2)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);
		
		//---DRAWING THE LINE---
		int line_height;
		int draw_start;
		int draw_end;

		line_height = (int)(WIN_HEIGHT / perp_wall_dist);
		draw_start = -line_height / 2 + WIN_HEIGHT / 2;
		if(draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + WIN_HEIGHT / 2;
		if(draw_end >= WIN_HEIGHT)
			draw_end = WIN_HEIGHT - 1;
		
		/*
		//calculate where the was hit exactly
		double wall_x;
		
		if (side % 2)
			wall_x = game->coord.pos_y + perp_wall_dist * ray_dir_y;
		else
			wall_x = game->coord.pos_x + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);
		
		int tex_x;

		tex_x = (int)(wall_x * (double)(TEX_WIDTH));
		if(side == 0 && ray_dir_x > 0)
			tex_x = TEX_WIDTH - tex_x - 1;
		if(side == 1 && ray_dir_y < 0)
			tex_x = TEX_WIDTH - tex_x - 1;

		double	step;

		step = 1.0 + TEX_HEIGHT / line_height;

		double tex_pos;

		tex_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;
		
		int				y;
		int				tex_y;
		unsigned int	color;
	
		y = draw_start;
		while (y < draw_end)
		{
			tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
			tex_pos += step;
			color = 
			y++;
		}
		*/

		int col;
		
		if (side == 0)
			col = BLUE;
		else if (side == 1)
			col = RED;
		else if (side == 2)
			col = YELLOW;
		else
			col = GREEN;
		
		ft_recolor_line(&game->bg, draw_start, draw_end, x, col);

		x++;
	}
}

void	ft_color_area(t_data *data, int start_y, int max_y, int color);

int	ft_deal_key(int key, t_game *game)
{
	if (key == ESC)
		ft_close(game);
	if (key == KEY_W || key == ARR_UP)
	{
		if (game->map[(int)(game->coord.pos_x + game->coord.dir_x * SPEED_MOVE)][(int)(game->coord.pos_y)] != '1')
			game->coord.pos_x += game->coord.dir_x * SPEED_MOVE;
		if (game->map[(int)(game->coord.pos_x)][(int)(game->coord.pos_y + game->coord.dir_y * SPEED_MOVE)] != '1')
			game->coord.pos_y += game->coord.dir_y * SPEED_MOVE;
	}
	else if (key == KEY_S || key == ARR_DOWN)
	{
		if (game->map[(int)(game->coord.pos_x - game->coord.dir_x * SPEED_MOVE)][(int)(game->coord.pos_y)] != '1')
			game->coord.pos_x -= game->coord.dir_x * SPEED_MOVE;
		if (game->map[(int)(game->coord.pos_x)][(int)(game->coord.pos_y - game->coord.dir_y * SPEED_MOVE)] != '1')
			game->coord.pos_y -= game->coord.dir_y * SPEED_MOVE;
	}
	else if (key == KEY_A)
	{
		if (game->map[(int)(game->coord.pos_x - game->coord.dir_y * SPEED_MOVE)][(int)(game->coord.pos_y)] != '1')
			game->coord.pos_x -= game->coord.dir_y * SPEED_MOVE;
		if (game->map[(int)(game->coord.pos_x)][(int)(game->coord.pos_y + game->coord.dir_x * SPEED_MOVE)] != '1')
			game->coord.pos_y += game->coord.dir_x * SPEED_MOVE;
	}
	else if (key == KEY_D)
	{
		if (game->map[(int)(game->coord.pos_x + game->coord.dir_y * SPEED_MOVE)][(int)(game->coord.pos_y)] != '1')
			game->coord.pos_x += game->coord.dir_y * SPEED_MOVE;
		if (game->map[(int)(game->coord.pos_x)][(int)(game->coord.pos_y - game->coord.dir_x * SPEED_MOVE)] != '1')
			game->coord.pos_y -= game->coord.dir_x * SPEED_MOVE;
	}
	else if (key == ARR_RIGHT)
	{
		game->coord.old_dir_x = game->coord.dir_x;
		game->coord.dir_x = game->coord.dir_x * cos(-SPEED_ROT) - game->coord.dir_y * sin(-SPEED_ROT);
		game->coord.dir_y = game->coord.old_dir_x * sin(-SPEED_ROT) + game->coord.dir_y * cos(-SPEED_ROT);
		game->coord.old_plane_x = game->coord.plane_x;
		game->coord.plane_x = game->coord.plane_x * cos(-SPEED_ROT) - game->coord.plane_y * sin(-SPEED_ROT);
		game->coord.plane_y = game->coord.old_plane_x * sin(-SPEED_ROT) + game->coord.plane_y * cos(-SPEED_ROT);
	}
	else if (key == ARR_LEFT)
	{
		game->coord.old_dir_x = game->coord.dir_x;
		game->coord.dir_x = game->coord.dir_x * cos(SPEED_ROT) - game->coord.dir_y * sin(SPEED_ROT);
		game->coord.dir_y = game->coord.old_dir_x * sin(SPEED_ROT) + game->coord.dir_y * cos(SPEED_ROT);
		game->coord.old_plane_x = game->coord.plane_x;
		game->coord.plane_x = game->coord.plane_x * cos(SPEED_ROT) - game->coord.plane_y * sin(SPEED_ROT);
		game->coord.plane_y = game->coord.old_plane_x * sin(SPEED_ROT) + game->coord.plane_y * cos(SPEED_ROT);
	}
	ft_color_area(&game->bg, 0, game->bg.height / 2, game->floor);
	ft_color_area(&game->bg, game->bg.height / 2, game->bg.height, game->ceiling);
	ft_view(game);
	mlx_put_image_to_window(game->mlx, game->win.ptr, game->bg.img, 0, 0);
	//ft_print_map(game);
	return (0);
}