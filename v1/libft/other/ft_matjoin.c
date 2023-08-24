/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:41:32 by abettini          #+#    #+#             */
/*   Updated: 2023/05/25 09:53:06 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matjoin(char **mat1, char **mat2)
{
	char	**mat;
	int		i;
	int		j;

	mat = malloc(sizeof(char *) * \
		(ft_matlen(mat1) + ft_matlen(mat2) + 1));
	if (!mat)
		return (NULL);
	i = 0;
	while (mat1 && mat1[i])
	{
		mat[i] = ft_strdup(mat1[i]);
		i++;
	}
	j = 0;
	while (mat2 && mat2[j])
	{
		mat[i + j] = ft_strdup(mat2[j]);
		j++;
	}
	mat[i + j] = NULL;
	return (mat);
}
