/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:56:04 by abettini          #+#    #+#             */
/*   Updated: 2023/05/25 10:02:38 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freemat(char **mat)
{
	int	i;

	if (mat)
	{
		i = 0;
		while (mat[i])
		{
			free(mat[i]);
			i++;
		}
		free(mat);
	}
}
