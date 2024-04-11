/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:41:18 by abettini          #+#    #+#             */
/*   Updated: 2024/04/11 11:40:50 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//----------------------------
//WALL-CHECK
/*

	if (!y || x >= ft_strlen(mat[y - 1]) || mat[y - 1][x] == ' ')
		return (1); // no wall above;

	if (!mat[y + 1] || x >= ft_strlen(mat[y + 1]) || mat[y + 1][x] == ' ')
		return (1); // no wall below;

	if (!x || mat[y][x - 1] == ' ')
		return (1); // no wall on the left;

	if (!mat[y][x + 1] || mat[y][x + 1] == ' ')
		return (1); // no wall on the right;

*/

int	ft_wall_check(char **mat, char *str)
{
	size_t	x;
	int		y;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (ft_strchr(str, mat[y][x]))
			{
				if ((!x || mat[y][x - 1] == ' ') || \
					(!mat[y][x + 1] || mat[y][x + 1] == ' '))
					return (1);
				if ((!y || x >= ft_strlen(mat[y - 1]) || \
					mat[y - 1][x] == ' ') || \
					(!mat[y + 1] || x >= ft_strlen(mat[y + 1]) \
					|| mat[y + 1][x] == ' '))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_elem_check(char **mat, char *str)
{
	int	x;
	int	y;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (!ft_strchr(str, mat[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_elem_count_check(char **mat, char *str)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x] && count < 2)
		{
			if (ft_strchr(str, mat[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (!(count == 1));
}

int	ft_check_map(char **mat)
{
	if (!mat || !*mat)
		return (ft_dprintf(2, "Error\nEmpty map.\n") * 0 + 1);
	else if (ft_elem_check(mat, "NSWE01 "))
		return (ft_dprintf(2, "Error\nInvalid elements.\n") * 0 + 1);
	else if (ft_elem_count_check(mat, "NSWE"))
		return (ft_dprintf(2, "Error\nInvalid amount of elements.\n") * 0 + 1);
	else if (ft_wall_check(mat, "NSWE0"))
		return (ft_dprintf(2, "Error\nInvalid walls.\n") * 0 + 1);
	return (0);
}
