/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:46:44 by abettini          #+#    #+#             */
/*   Updated: 2023/08/25 16:32:10 by abettini         ###   ########.fr       */
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
			check = ft_dprintf(2, "Error\nElement surplus.\n") * 0 + 1;
		free(line);
	}
	return (check);
}

void	ft_print_info(t_game *game)
{
	write(1, "\n", 1);
	printf("north   = %s\n", game->n.path);
	printf("south   = %s\n", game->s.path);
	printf("west    = %s\n", game->w.path);
	printf("east    = %s\n", game->e.path);
	printf("floor   = %d\n", game->floor);
	printf("ceiling = %d\n", game->ceiling);
	write(1, "\n", 1);
	ft_printmat(game->map);
	write(1, "\n", 1);
}

int	ft_get_info(t_game *game, char *path)
{
	int		fd;
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
	{
		ft_get_imgs_data(game);
		ft_print_info(game);
	}
	close (fd);
	return (check);
}
