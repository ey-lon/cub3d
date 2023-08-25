/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:05:36 by abettini          #+#    #+#             */
/*   Updated: 2023/08/01 14:57:06 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_mod(char *str, char end)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != end)
			i++;
	}
	return (i);
}

int	ft_strlen_mod2(char *str, char *end)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] && !ft_strchr(end, str[i]))
			i++;
	}
	return (i);
}
