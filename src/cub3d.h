/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:43:14 by abettini          #+#    #+#             */
/*   Updated: 2023/07/28 16:31:45 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define SPACES "\t\n\v\f\r "
# define WIN_NAME "cub3d"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

typedef struct s_image
{
	char	*path;
	void	*ptr;
	int		height;
	int		width;
}	t_image;

typedef struct s_window
{
	void	*ptr;
	int		height;
	int		width;
}	t_window;

typedef struct s_game
{
	t_image		n;
	t_image		s;
	t_image		w;
	t_image		e;
	int			ceiling;
	int			floor;
	char		**map;
	void		*mlx;
	t_window	win;
}	t_game;

int		ft_get_info(t_game *game, char *path);
int		ft_get_fd(char *path, char *type);
int		ft_get_textures(t_game *game, int fd);
int		ft_get_map(t_game *game, int fd);
int		ft_check_map(char **mat);
void	ft_get_imgs_xpm(t_game *game);

//FREE---------------------------------------
void	ft_free_imgs_paths(t_game *game);
void	ft_free_game(t_game *game);

#endif
