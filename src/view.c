/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:03:39 by abettini          #+#    #+#             */
/*   Updated: 2023/08/23 11:02:09 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_recolor_pixel(t_data *data, int x, int y, int color);

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
				side = 1 + step_x;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 2 + step_y;
			}
			if (map_x >= game->mh || map_y >= game->mw || map_x < 0 || map_y < 0)
				break ;
			if (game->map[map_x][map_y] == '1')
				hit = 1;
		}
		if (!(map_x >= game->mh || map_y >= game->mw || map_x < 0 || map_y < 0))
		{
			if (side % 2 == 0)
				perp_wall_dist = (side_dist_x - delta_dist_x);
			else
				perp_wall_dist = (side_dist_y - delta_dist_y);
			
			//---DRAWING THE LINE---
			int line_height;
			int draw_start;
			int draw_end;

			line_height = (int)(WIN_HEIGHT / perp_wall_dist);
			draw_start = -line_height / 2 + WIN_HEIGHT / 2;
			if (draw_start < 0)
				draw_start = 0;
			draw_end = line_height / 2 + WIN_HEIGHT / 2;
			if (draw_end >= WIN_HEIGHT)
				draw_end = WIN_HEIGHT - 1;
			
			//calculate where the was hit exactly
			double wall_x;
			
			if (side % 2 == 0)
				wall_x = game->coord.pos_y + perp_wall_dist * ray_dir_y;
			else
				wall_x = game->coord.pos_x + perp_wall_dist * ray_dir_x;
			wall_x -= floor(wall_x);
			
			int tex_x;

			tex_x = (int)(wall_x * (double)(TEX_WIDTH));
			if (side % 2 == 0 && ray_dir_x > 0)
				tex_x = TEX_WIDTH - tex_x - 1;
			if (side % 2 == 1 && ray_dir_y < 0)
				tex_x = TEX_WIDTH - tex_x - 1;

			double	step;

			step = 1.0 + TEX_HEIGHT / line_height;

			double tex_pos;

			tex_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;

			int				y;
			int				tex_y;
			int				color;
			char			*pixel;

			y = draw_start;
			while (y < draw_end)
			{
				tex_y = (int)tex_pos % TEX_HEIGHT;
				tex_pos += step;
				if (side == 0)
					pixel = game->n.addr + ((tex_y * game->n.line_length) + (tex_x * (game->n.bits_per_pixel / 8)));
				else if (side == 1)
					pixel = game->w.addr + ((tex_y * game->w.line_length) + (tex_x * (game->w.bits_per_pixel / 8)));
				else if (side == 2)
					pixel = game->s.addr + ((tex_y * game->s.line_length) + (tex_x * (game->s.bits_per_pixel / 8)));
				else
					pixel = game->e.addr + ((tex_y * game->e.line_length) + (tex_x * (game->e.bits_per_pixel / 8)));
				color = *(int *)pixel;
				ft_recolor_pixel(&game->bg, x, y, color);
				y++;
			}
			
			/* 
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
			*/
		}
		x++;
	}
}
