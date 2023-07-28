/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:40:53 by abettini          #+#    #+#             */
/*   Updated: 2023/07/28 10:24:35 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_single_col(char **s, int comma)
{
	char	*str;
	int		col;
	int		i;

	str = *s;
	col = ft_atoi(str);
	if (!*str || col > 255 || col < 0)
		return (-1);
	i = 0;
	while (*str && *str != '\n' && i < 3)
	{
		if (ft_isdigit(*str))
			str++;
		else if (comma == 1 && i > 0 && *str == ',')
			break ;
		else
			return (-1);
		i++;
	}
	if (comma == 1 && *str == ',')
		str++;
	else if ((comma == 1 && *str != ',') || (*str && !ft_isspace(*str)))
		return (-1);
	*s = str;
	return (col);
}

int	ft_get_color(int *color, char **s)
{
	char	*str;
	int		r;
	int		g;
	int		b;

	str = *s;
	if (*color != -1 || !ft_isspace(str[1]))
		return (-1);
	str += 1;
	while (ft_isspace(*str))
		str++;
	if (!*str)
		return (-1);
	r = ft_get_single_col(&str, 1);
	if (r != -1)
		g = ft_get_single_col(&str, 1);
	if (r != -1 && g != -1)
		b = ft_get_single_col(&str, 0);
	if (r != -1 && g != -1 && b != -1)
		*color = (r << 16) + (g << 8) + (b << 0);
	else
		return (ft_dprintf(2, "Error\nInvalid color.\n") * 0 - 1);
	*s = str;
	return (1);
}

//((RED << 16) + (GREEN << 8) + (BLUE << 0))
