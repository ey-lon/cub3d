/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:39:02 by abettini          #+#    #+#             */
/*   Updated: 2023/07/27 18:03:04 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_type_check(char *path, char *type)
{
	return (ft_rev_strncmp(path, type, ft_strlen(type)));
}

int	ft_check_ifdir(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd == -1)
		return (0);
	ft_dprintf(2, "Error\nPath is a directory: %s\n", path);
	close(fd);
	return (1);
}

int	ft_get_fd(char *path, char *type)
{
	int	fd;

	if (ft_type_check(path, type))
	{
		fd = -1;
		ft_dprintf(2, "Error\nInvalid file type: %s (expected \"%s\").\n", \
			path, type);
	}
	else if (!ft_check_ifdir(path))
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
			ft_dprintf(2, "Error\nInvalid path: %s\n", path);
	}
	return (fd);
}
