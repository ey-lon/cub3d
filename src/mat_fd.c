/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:29:04 by abettini          #+#    #+#             */
/*   Updated: 2023/06/02 11:29:37 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_freejoin(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

int	ft_get_mat_fd(int fd)
{
	char	*line;
	char	*rawmat;
	char	**mat;

	mat = NULL;
	if (fd != -1)
	{
		rawmat = malloc(1);
		if (!rawmat)
			return (NULL);
		*rawmat = '\0';
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			rawmat = ft_freejoin(rawmat, line);
		}
		mat = ft_split(rawmat, '\n');
		free(rawmat);
	}
	return (mat);
}