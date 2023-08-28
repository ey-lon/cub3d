/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:43:14 by abettini          #+#    #+#             */
/*   Updated: 2023/08/28 17:41:34 by abettini         ###   ########.fr       */
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
# define SPEED_MOVE 0.15
# define SPEED_ROT 0.05
# define WALL_OFFSET 0.1
# define PI 3.1415926535

# define FOV 0.66
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define TS 64

# define UP_P 1
# define DOWN_P 2
# define LEFT_P 4
# define RIGHT_P 8
# define ROT_L_P 16
# define ROT_R_P 32

typedef struct s_data
{
	char	*path;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_data;

typedef struct s_window
{
	void	*ptr;
	int		height;
	int		width;
}	t_window;

typedef struct s_coord
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		old_dir_x;
	double		old_plane_x;
}	t_coord;

typedef struct s_cam
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;
}	t_cam;

typedef struct s_line
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}	t_line;

typedef struct s_game
{
	void		*mlx;
	t_window	win;
	char		keys_pressed;
	char		minimap;
	char		event;
	t_coord		coord;
	t_data		n;
	t_data		s;
	t_data		w;
	t_data		e;
	t_data		bg;
	int			ceiling;
	int			floor;
	char		**map;
	int			map_height;
	int			map_width;
}	t_game;

//-------------------------------------------
//INIT
int		ft_get_info(t_game *game, char *path);
int		ft_get_fd(char *path, char *type);
int		ft_get_textures(t_game *game, int fd);
int		ft_get_map(t_game *game, int fd);
int		ft_check_map(char **mat);
void	ft_get_imgs_data(t_game *game);
void	ft_init_coord(t_game *game);

//-------------------------------------------
//COLORS
int		ft_get_pixel_color(t_data *data, int x, int y);
void	ft_recolor_pixel(t_data *data, int x, int y, int color);
void	ft_color_area(t_data *data, int start_y, int max_y, int color);

//-------------------------------------------
//BACKGROUND
void	ft_new_bg(t_game *game);
void	ft_minimap(t_game *game);

//LOOP
int		ft_deal_key(int key, t_game *game);
int		ft_release_key(int key, t_game *game);
int		ft_loop(t_game *game);

//-------------------------------------------
//MOVE
void	ft_key_move_up(t_game *game);
void	ft_key_move_down(t_game *game);
void	ft_key_move_left(t_game *game);
void	ft_key_move_right(t_game *game);
//ROTATE
void	ft_key_rotate_left(t_game *game);
void	ft_key_rotate_right(t_game *game);

//-------------------------------------------
//RAYCASTING
void	ft_raycasting(t_game *game);
void	ft_raycasting_2(t_game *game, t_cam *cam, int x);

//-------------------------------------------
//FREE
void	ft_free_imgs_paths(t_game *game);
void	ft_free_game(t_game *game);

//-------------------------------------------
//UTILS
int		ft_max_len(char **mat);
double	ft_fabs(double n);

//-------------------------------------------
//PRINT_MAP
void	ft_print_map(t_game *game);

#endif
