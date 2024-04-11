/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:03:39 by abettini          #+#    #+#             */
/*   Updated: 2024/04/11 11:59:09 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_v1(t_game *game, t_cam *cam, int x)
{
	cam->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	cam->ray_dir_x = game->coord.dir_x + game->coord.plane_x * cam->camera_x;
	cam->ray_dir_y = game->coord.dir_y + game->coord.plane_y * cam->camera_x;
	cam->map_x = game->coord.pos_x;
	cam->map_y = game->coord.pos_y;
	if (cam->ray_dir_x)
		cam->delta_dist_x = ft_fabs(1 / cam->ray_dir_x);
	else
		cam->delta_dist_x = (float)INT_MAX;
	if (cam->ray_dir_y)
		cam->delta_dist_y = ft_fabs(1 / cam->ray_dir_y);
	else
		cam->delta_dist_y = (float)INT_MAX;
}

static void	ft_v2(t_game *game, t_cam *cam)
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

static int	ft_v3(t_game *game, t_cam *cam)
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

int	ft_raycasting_1(t_game *game, t_cam *cam, int x)
{
	ft_v1(game, cam, x);
	ft_v2(game, cam);
	return (ft_v3(game, cam));
}

void	ft_raycasting(t_game *game)
{
	int		x;
	t_cam	cam;

	x = 0;
	while (x < WIN_WIDTH)
	{
		if (ft_raycasting_1(game, &cam, x))
			ft_raycasting_2(game, &cam, x);
		x++;
	}
}
