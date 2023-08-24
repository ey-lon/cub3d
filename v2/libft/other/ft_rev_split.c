/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:57:35 by abettini          #+#    #+#             */
/*   Updated: 2023/08/01 14:50:03 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rev_split(char **mat)
{
	char	*str;
	char	*temp;
	int		y;

	if (!mat || !*mat)
		return (NULL);
	temp = malloc(sizeof(char) * 1);
	if (!temp)
		return (NULL);
	*temp = '\0';
	y = 0;
	while (mat[y])
	{
		str = ft_strjoin(temp, mat[y]);
		free(temp);
		temp = str;
		y++;
	}
	return (str);
}
