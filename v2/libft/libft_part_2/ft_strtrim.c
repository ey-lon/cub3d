/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:46:41 by abettini          #+#    #+#             */
/*   Updated: 2023/08/01 14:51:01 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	if (s1 != 0 && set != 0)
	{
		while (s1[i] && ft_strchr(set, s1[i]) != 0)
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) != 0 && j > i)
			j--;
		p = malloc(sizeof(char) * (j - i + 1));
		if (!p)
			return (NULL);
		ft_strlcpy(p, &s1[i], j - i + 1);
	}
	else
	{
		p = malloc(sizeof(char));
		if (!p)
			return (NULL);
		*p = '\0';
	}
	return (p);
}
