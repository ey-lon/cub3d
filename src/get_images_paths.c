/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:40:15 by abettini          #+#    #+#             */
/*   Updated: 2023/08/14 10:36:38 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_img_path(char *path)
{
	int		fd;

	fd = ft_get_fd(path, ".xpm");
	if (fd == -1)
	{
		free(path);
		return (1);
	}
	close (fd);
	return (0);
}

int	ft_check_img_err(char *str, void *img)
{
	if (!ft_isspace(str[2]))
	{
		ft_dprintf(2, "Error\nInvalid info\n");
		return (1);
	}
	else if (img != 0)
	{
		ft_dprintf(2, "Error\nReassignment of texture.\n");
		return (1);
	}
	return (0);
}

int	ft_get_img_path(void *mlx, t_data *data, char **s)
{
	int		len;
	char	*path;
	char	*str;

	str = *s;
	if (ft_check_img__err(str, data->img))
		return (-1);
	str += 2;
	while (ft_isspace(*str))
		str++;
	if (!*str)
		return (-1);
	len = ft_strlen_mod2(str, SPACES);
	path = ft_substr(str, 0, len);
	if (ft_check_img_path(path))
		return (-1);
	data->path = path;
	str += len;
	*s = str;
	return (1);
}
