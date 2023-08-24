/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:03:39 by abettini          #+#    #+#             */
/*   Updated: 2023/08/24 11:08:52 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_recolor_pixel(t_data *data, int x, int y, int color);

void	ft_v1(t_game *game, t_cam *cam, int x)
{
	cam->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	cam->ray_dir_x = game->coord.dir_x + game->coord.plane_x * cam->camera_x;
	cam->ray_dir_y = game->coord.dir_y + game->coord.plane_y * cam->camera_x;
	cam->map_x = game->coord.pos_x;
	cam->map_y = game->coord.pos_y;
	if (cam->ray_dir_x)
		cam->delta_dist_x = fabs(1 / cam->ray_dir_x);
	else
		cam->delta_dist_x = (float)INT_MAX;
	if (cam->ray_dir_y)
		cam->delta_dist_y = fabs(1 / cam->ray_dir_y);
	else
		cam->delta_dist_y = (float)INT_MAX;
}

void	ft_v2(t_game *game, t_cam *cam)
{
	if (cam->ray_dir_x < 0)
	{
		cam->step_x = -1;
		cam->side_dist_x = (game->coord.pos_x - cam->map_x) * \
			cam->delta_dist_x;
	}
	else
	{
		cam->step_x = 1;
		cam->side_dist_x = (cam->map_x + 1.0 - game->coord.pos_x) * \
			cam->delta_dist_x;
	}
	if (cam->ray_dir_y < 0)
	{
		cam->step_y = -1;
		cam->side_dist_y = (game->coord.pos_y - cam->map_y) * \
			cam->delta_dist_y;
	}
	else
	{
		cam->step_y = 1;
		cam->side_dist_y = (cam->map_y + 1.0 - game->coord.pos_y) * \
			cam->delta_dist_y;
	}
}

int	ft_v3(t_game *game, t_cam *cam)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (cam->side_dist_x < cam->side_dist_y)
		{
			cam->side_dist_x += cam->delta_dist_x;
			cam->map_x += cam->step_x;
			cam->side = 1 + cam->step_x;
		}
		else
		{
			cam->side_dist_y += cam->delta_dist_y;
			cam->map_y += cam->step_y;
			cam->side = 2 + cam->step_y;
		}
		if (cam->map_x >= game->map_height || cam->map_y >= game->map_width \
			|| cam->map_x < 0 || cam->map_y < 0)
			break ;
		else if (game->map[cam->map_x][cam->map_y] == '1')
			hit = 1;
	}
	return (hit);
}

void	ft_v4(t_game *game, t_cam *cam, t_line *line)
{
	if (cam->side % 2 == 0)
		cam->perp_wall_dist = (cam->side_dist_x - cam->delta_dist_x);
	else
		cam->perp_wall_dist = (cam->side_dist_y - cam->delta_dist_y);
	line->line_height = (int)(WIN_HEIGHT / cam->perp_wall_dist);
	line->draw_start = -(line->line_height) / 2 + WIN_HEIGHT / 2;
	if (line->draw_start < 0)
		line->draw_start = 0;
	line->draw_end = line->line_height / 2 + WIN_HEIGHT / 2;
	if (line->draw_end >= WIN_HEIGHT)
		line->draw_end = WIN_HEIGHT - 1;
}

void	ft_v5(t_game *game, t_cam *cam, t_line *line)
{
	if (cam->side % 2 == 0)
		line->wall_x = game->coord.pos_y + cam->perp_wall_dist * cam->ray_dir_y;
	else
		line->wall_x = game->coord.pos_x + cam->perp_wall_dist * cam->ray_dir_x;
	line->wall_x -= (int)(line->wall_x);
	line->tex_x = (int)(line->wall_x * (double)(TEX_WIDTH));
	if (cam->side % 2 == 0 && cam->ray_dir_x > 0)
		line->tex_x = TEX_WIDTH - line->tex_x - 1;
	if (cam->side % 2 == 1 && cam->ray_dir_y < 0)
		line->tex_x = TEX_WIDTH - line->tex_x - 1;
	line->step = (double)TEX_HEIGHT / line->line_height;
	line->tex_pos = (line->draw_start - WIN_HEIGHT / 2 + line->line_height / 2) * line->step;
}

void	ft_v6(t_game *game, t_cam *cam, t_line *line, int x)
{
	int		y;
	int		color;
	char	*pixel;

	y = line->draw_start;
	while (y < line->draw_end)
	{
		line->tex_y = (int)(line->tex_pos) % TEX_HEIGHT;
		if (cam->side == 0)
			pixel = game->n.addr + ((line->tex_y * game->n.line_length) + (line->tex_x * (game->n.bits_per_pixel / 8)));
		else if (cam->side == 1)
			pixel = game->w.addr + ((line->tex_y * game->w.line_length) + (line->tex_x * (game->w.bits_per_pixel / 8)));
		else if (cam->side == 2)
			pixel = game->s.addr + ((line->tex_y * game->s.line_length) + (line->tex_x * (game->s.bits_per_pixel / 8)));
		else if (cam->side == 3)
			pixel = game->e.addr + ((line->tex_y * game->e.line_length) + (line->tex_x * (game->e.bits_per_pixel / 8)));
		color = *(int *)pixel;
		ft_recolor_pixel(&game->bg, x, y, color);
		line->tex_pos += line->step;
		y++;
	}
}

void	ft_view(t_game *game)
{
	int		x;
	t_cam	cam;
	t_line	line;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_v1(game, &cam, x);
		ft_v2(game, &cam);
		if (ft_v3(game, &cam))
		{
			ft_v4(game, &cam, &line);
			ft_v5(game, &cam, &line);
			ft_v6(game, &cam, &line, x);
		}
		x++;
	}
}

/* void	ft_view(t_game *game)
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
			if (map_x >= game->map_height || map_y >= game->map_width || map_x < 0 || map_y < 0)
				break ;
			else if (game->map[map_x][map_y] == '1')
				hit = 1;
		}
		if (!(map_x >= game->map_height || map_y >= game->map_width || map_x < 0 || map_y < 0))
		{
			if (side % 2 == 0)
				perp_wall_dist = (side_dist_x - delta_dist_x);
			else
				perp_wall_dist = (side_dist_y - delta_dist_y);
			
			//---DRAWING THE LINE---
			int		line_height;
			int		draw_start;
			int		draw_end;
			double	wall_x;
			int		tex_x;
			double	step;
			double	tex_pos;

			line_height = (int)(WIN_HEIGHT / perp_wall_dist);
			draw_start = -line_height / 2 + WIN_HEIGHT / 2;
			if (draw_start < 0)
				draw_start = 0;
			draw_end = line_height / 2 + WIN_HEIGHT / 2;
			if (draw_end >= WIN_HEIGHT)
				draw_end = WIN_HEIGHT - 1;
			
			//calculate where the was hit exactly
			
			if (side % 2 == 0)
				wall_x = game->coord.pos_y + perp_wall_dist * ray_dir_y;
			else
				wall_x = game->coord.pos_x + perp_wall_dist * ray_dir_x;
			wall_x -= (int)(wall_x);
			

			tex_x = (int)(wall_x * (double)(TEX_WIDTH));
			if (side % 2 == 0 && ray_dir_x > 0)
				tex_x = TEX_WIDTH - tex_x - 1;
			if (side % 2 == 1 && ray_dir_y < 0)
				tex_x = TEX_WIDTH - tex_x - 1;

			
			step = (double)TEX_HEIGHT / line_height;


			tex_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;

			int				y;
			int				tex_y;
			int				color;
			char			*pixel;

			y = draw_start;
			while (y < draw_end)
			{
				tex_y = (int)tex_pos % TEX_HEIGHT;
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
				tex_pos += step;
				y++;
			}
		}
		x++;
	}
} */
