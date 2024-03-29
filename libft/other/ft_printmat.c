/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:55:34 by abettini          #+#    #+#             */
/*   Updated: 2023/07/27 14:07:03 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printmat(char **mat)
{
	int	y;

	if (mat)
	{
		y = 0;
		while (mat[y])
		{
			ft_putstr_fd(mat[y], 1);
			write(1, "\n", 1);
			y++;
		}
	}
}
