/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ult_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:26:20 by abettini          #+#    #+#             */
/*   Updated: 2023/06/13 16:39:50 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_ult_strjoin(int n, ...)
{
	va_list	ap;
	char	*str;
	char	*temp;

	if (n < 1)
		return (NULL);
	temp = malloc(sizeof(char) * 1);
	if (temp)
		return (NULL);
	*temp = '\0';
	va_start(ap, n);
	while (n > 0)
	{
		str = ft_strjoin(temp, va_arg(ap, char *));
		free(temp);
		temp = str;
		n--;
	}
	va_end(ap);
	return (str);
}

//this function joins all the strings passed as arguments in a single string.

/*
#include <stdio.h>

int main(int ac, char **av)
{
	char *str;

	str = ft_ult_strjoin(4, "str1 ", "str2 ", "str3 ", "str4");
	printf("%s", str);
	free(str);
	return (0);
}
*/