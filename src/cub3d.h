/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:43:14 by abettini          #+#    #+#             */
/*   Updated: 2023/07/27 17:37:51 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# define SPACES "\t\n\v\f\r "

typedef struct s_image
{
	char	*path;
	void	*img;
	int		height;
	int		width;
}	t_image;

typedef struct s_game
{
	t_image	n;
	t_image	s;
	t_image	w;
	t_image	e;
	int		ceiling;
	int		floor;
	char	**map;
	void	*mlx;
	void	*win;
}	t_game;

int		ft_get_info(t_game *game, char *path);
int		ft_get_fd(char *path, char *type);
int		ft_get_textures(t_game *game, int fd);
int		ft_get_map(t_game *game, int fd);
int		ft_check_map(char **mat);
void	ft_get_imgs_xpm(t_game *game);

//FREE---------------------------------------
void	ft_free_imgs_paths(t_game *game);

#endif
