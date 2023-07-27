/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:46:44 by abettini          #+#    #+#             */
/*   Updated: 2023/07/27 17:37:19 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_leftovers(int fd)
{
	char	*line;
	int		check;

	check = 0;
	line = NULL;
	while (!check)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (*line != '\n')
			check = 1;
		free(line);
	}
	return (check);
}

int	ft_get_info(t_game *game, char *path)
{
	int		fd;
	char	**map;
	int		check;

	fd = ft_get_fd(path, ".cub");
	if (fd < 0)
		return (1);
	check = ft_get_textures(game, fd);
	if (!check)
		check = ft_get_map(game, fd);
	if (!check)
		check = ft_check_leftovers(fd);
	if (check)
	{
		ft_free_imgs_paths(game);
		ft_freemat(game->map);
	}
	else
		ft_get_imgs_xpm(game);
	close (fd);
	return (check);
}
