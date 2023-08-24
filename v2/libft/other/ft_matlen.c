/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:39:57 by abettini          #+#    #+#             */
/*   Updated: 2023/08/01 15:09:48 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matlen(char **mat)
{
	int	i;

	i = 0;
	if (mat)
	{
		while (mat[i])
			i++;
	}
	return (i);
}

int	ft_matlen_mod(char **mat, char *end)
{
	int	i;

	i = 0;
	if (mat)
	{
		while (mat[i] && ft_strcmp(mat[i], end))
			i++;
	}
	return (i);
}
