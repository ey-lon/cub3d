/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:40:37 by abettini          #+#    #+#             */
/*   Updated: 2023/06/02 11:41:59 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_game(char *path)
{
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf("Invalid number of arguments.\n") * 0 + 1);
	if (ft_map_check(av[1]))
		return (1);
	ft_game(av[1]);
	return (0);
}