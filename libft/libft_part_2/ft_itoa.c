/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:41:23 by abettini          #+#    #+#             */
/*   Updated: 2023/08/01 14:31:56 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_in_str(int nbr, char *str, int len)
{
	long	n;

	str[len] = '\0';
	n = nbr;
	if (n >= 0)
	{
		while (len >= 1)
		{
			len--;
			str[len] = (n % 10) + '0';
			n = n / 10;
		}
	}
	else
	{
		str[0] = '-';
		n = -n;
		while (len > 1)
		{
			len--;
			str[len] = (n % 10) + '0';
			n = n / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			temp;

	temp = n;
	if (n == -2147483648)
		len = 11;
	else
	{
		len = 1;
		if (n < 0 && ++len)
			temp = -temp;
		while (temp >= 10 && ++len)
			temp = temp / 10;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_putnbr_in_str(n, str, len);
	return (str);
}

/*
#include <stdio.h>

int	main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(9));
	printf("%s\n", ft_itoa(-9));
	printf("%s\n", ft_itoa(10));
	printf("%s\n", ft_itoa(-10));
	printf("%s\n", ft_itoa(8124));
	printf("%s\n", ft_itoa(-9874));
	printf("%s\n", ft_itoa(543000));
	printf("%s\n", ft_itoa(-2147483648LL));
	printf("%s\n", ft_itoa(2147483647));
}
*/
