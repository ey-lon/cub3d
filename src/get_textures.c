/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:40:11 by abettini          #+#    #+#             */
/*   Updated: 2024/04/11 12:12:57 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_img_path(t_data *img, char **s);
int	ft_get_color(int *color, char **s);

static int	ft_compare_one(t_game *game, char **str)
{
	int	check;

	check = 0;
	if (!ft_strncmp(*str, "NO", 2))
		check = ft_get_img_path(&game->n, str);
	else if (!ft_strncmp(*str, "SO", 2))
		check = ft_get_img_path(&game->s, str);
	else if (!ft_strncmp(*str, "WE", 2))
		check = ft_get_img_path(&game->w, str);
	else if (!ft_strncmp(*str, "EA", 2))
		check = ft_get_img_path(&game->e, str);
	else if (!ft_strncmp(*str, "F", 1))
		check = ft_get_color(&game->floor, str);
	else if (!ft_strncmp(*str, "C", 1))
		check = ft_get_color(&game->ceiling, str);
	else if (**str)
		check = ft_dprintf(2, "Error\nInvalid info.\n") * 0 - 1;
	return (check);
}

static int	ft_get_img_col(t_game *game, char *str, int old_check)
{
	int	check;

	if (!ft_strncmp(str, "\n", 1))
		return (old_check);
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		check = ft_compare_one(game, &str);
		if (check == -1)
			return (-1);
		old_check += check;
	}
	return (old_check);
}

int	ft_get_textures(t_game *game, int fd)
{
	char	*line;
	int		check;

	check = 0;
	while (check < 6 && check > -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check = ft_get_img_col(game, line, check);
		free(line);
	}
	if (check == -1)
		return (1);
	else if (check != 6)
		return (ft_dprintf(2, "Error\nNot enough info.\n") * 0 + 1);
	return (0);
}

//6 are the info to get (NO, SO, WE, EA, FLOOR, CEILING)
