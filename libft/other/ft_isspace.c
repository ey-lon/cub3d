/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:19:05 by abettini          #+#    #+#             */
/*   Updated: 2023/05/30 14:25:08 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

/*
9  '\t' (horizontal tab)
10 '\n' (new line)
11 '\v' (vertical tab)
12 '\f' (form feed)
13 '\r' (carriage ret)
32 ' '  SPACE
*/