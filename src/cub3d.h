/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:43:14 by abettini          #+#    #+#             */
/*   Updated: 2023/08/10 10:04:17 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include "keycodes.h"
# include "colors.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define SPACES "\t\n\v\f\r "
# define WIN_NAME "cub3d"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define SPEED_MOVE 0.1
# define SPEED_ROT 0.0001
# define PI 3.1415926535

# define TS 64

typedef struct s_image
{
	char	*path;
	void	*ptr;
	int		height;
	int		width;
}	t_image;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


typedef struct s_window
{
	void	*ptr;
	int		height;
	int		width;
}	t_window;

typedef struct s_coord
{
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		old_dir_x;
	float		old_plane_x;
}	t_coord;

typedef struct s_cam
{
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;
	float	delta_dist_x;
	float	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int 	step_x;
	int		step_y;
}	t_cam;

typedef struct s_line
{
	int line_height;
	int draw_start;
	int draw_end;
}	t_line;

typedef struct s_game
{
	t_image		n;
	t_image		s;
	t_image		w;
	t_image		e;
	t_data		bg;
	int			ceiling;
	int			floor;
	char		**map;
	void		*mlx;
	t_window	win;
	int			mh;
	int			mw;
	t_coord		coord;
}	t_game;

int		ft_get_info(t_game *game, char *path);
int		ft_get_fd(char *path, char *type);
int		ft_get_textures(t_game *game, int fd);
int		ft_get_map(t_game *game, int fd);
int		ft_check_map(char **mat);
void	ft_get_imgs_xpm(t_game *game);
void	ft_init_coord(t_game *game);
void	ft_bg_img(t_game *game);

//FREE---------------------------------------
void	ft_free_imgs_paths(t_game *game);
void	ft_free_game(t_game *game);

//UTILS--------------------------------------
int		ft_max_len(char **mat);

//PRINT_MAP----------------------------------
void	ft_print_map(t_game *game);

#endif
