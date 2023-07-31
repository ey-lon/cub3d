/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:02:01 by abettini          #+#    #+#             */
/*   Updated: 2023/07/31 11:02:20 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_max_len(char **mat)
{
	int x;
	int y;
	int len;
	int	t_len;

	len = 0;
	y = 0;
	while (mat[y])
	{
		t_len = ft_strlen(mat[y]);
		if (t_len > len)
			len = t_len;
		y++;
	}
	return (len);
}