/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:46:44 by abettini          #+#    #+#             */
/*   Updated: 2023/06/02 11:41:54 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_wall_check(char **mat)
{
	return (0);
}

int	ft_elem_check(char **mat)
{
	return (0);
}

int	ft_mat_error_check(char **mat)
{
	if (!mat)
		return (printf("Empty map.\n") * 0 + 1);
	else if (ft_wall_check(mat))
		return (printf("Invalid walls.\n"));
	else if (ft_elem_check(mat))
		return (printf("Invalid elements.\n"));
	return (0);
}

int	ft_type_check(char *path, char *type)
{
	return (ft_rev_strncmp(path, type, ft_strlen(type)));
}

int	ft_map_check(char *path)
{
	int		fd;
	char	**map;

	if (ft_type_check(path, ".cub"))
		return (printf("Invalid file type.\n") * 0 + 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (printf("Invalid path.\n") * 0 + 1);
	map = ft_get_mat_fd(fd);
	close(fd);
	if (ft_mat_error_check(map))
	{
		ft_freemat(map);
		return (1);
	}
	return (0);
}