/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:29:04 by abettini          #+#    #+#             */
/*   Updated: 2024/04/11 12:12:04 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_freejoin(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

static char	*ft_get_first_line(int fd)
{
	char	*line;
	int		start;

	start = 0;
	line = NULL;
	while (!start)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (*line == '\n')
		{
			free(line);
			line = NULL;
		}
		else
			start = 1;
	}
	return (line);
}

static char	**ft_get_map_fd(int fd)
{
	char	*line;
	char	*rawmat;
	char	**mat;

	mat = NULL;
	if (fd > -1)
	{
		rawmat = ft_get_first_line(fd);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			if (*line == '\n')
			{
				free(line);
				break ;
			}
			rawmat = ft_freejoin(rawmat, line);
		}
		if (rawmat)
			mat = ft_split(rawmat, '\n');
		free(rawmat);
	}
	return (mat);
}

int	ft_get_map(t_game *game, int fd)
{
	int	check;

	game->map = ft_get_map_fd(fd);
	check = ft_check_map(game->map);
	return (check);
}
