/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_strncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:05:53 by abettini          #+#    #+#             */
/*   Updated: 2023/08/01 14:57:02 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rev_strncmp(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (i >= 0 && j >= 0 && n > 0)
	{
		if (s1[i] != s2[j])
			return (s1[i] - s2[j]);
		i--;
		j--;
		n--;
	}
	if (n != 0 && i < 0 && j >= 0)
		return (s2[j]);
	else if (n != 0 && j < 0 && i >= 0)
		return (s1[i]);
	return (0);
}
