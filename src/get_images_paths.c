/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:40:15 by abettini          #+#    #+#             */
/*   Updated: 2023/07/28 15:27:33 by abettini         ###   ########.fr       */
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

int	ft_get_img_path(void *mlx, t_image *img, char **s)
{
	int		len;
	char	*path;
	char	*str;

	str = *s;
	if (img->ptr || !ft_isspace(str[2]))
		return (ft_dprintf(2, "Error\nInvalid info\n") * 0 - 1);
	str += 2;
	while (ft_isspace(*str))
		str++;
	if (!*str)
		return (-1);
	len = ft_strlen_mod2(str, SPACES);
	path = ft_substr(str, 0, len);
	if (ft_check_img_path(path))
		return (-1);
	img->path = path;
	str += len;
	*s = str;
	return (1);
}
