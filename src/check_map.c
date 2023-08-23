/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:41:18 by abettini          #+#    #+#             */
/*   Updated: 2023/08/23 16:02:25 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_wall_check(char **mat)
{
	int	x;
	int	y;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (ft_strchr("NSWE0", mat[y][x]))
			{
				if (!y || x >= ft_strlen(mat[y - 1]) || mat[y - 1][x] == ' ')
					return (1);
				if (!mat[y + 1] || x >= ft_strlen(mat[y + 1]) || mat[y + 1][x] == ' ')
					return (1);
				if (!x || mat[y][x - 1] == ' ')
					return (1);
				if (!mat[y][x + 1] || mat[y][x + 1] == ' ')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_elem_check(char **mat)
{
	int	x;
	int	y;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (!ft_strchr("NSWE01 ", mat[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_elem_count_check(char **mat)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (ft_strchr("NSWE", mat[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count - 1);
}

int	ft_check_map(char **mat)
{
	if (!mat)
		return (ft_dprintf(2, "Error\nEmpty map.\n") * 0 + 1);
	else if (ft_wall_check(mat))
		return (ft_dprintf(2, "Error\nInvalid walls.\n") * 0 + 1);
	else if (ft_elem_check(mat))
		return (ft_dprintf(2, "Error\nInvalid elements.\n") * 0 + 1);
	else if (ft_elem_count_check(mat))
		return (ft_dprintf(2, "Error\nInvalid amount of elements.\n") * 0 + 1);
	return (0);
}
