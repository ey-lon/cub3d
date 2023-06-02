/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ult_matjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:53:47 by abettini          #+#    #+#             */
/*   Updated: 2023/05/25 10:02:28 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_ult_matjoin(int n, ...)
{
	va_list	ap;
	char	**tmp;
	char	**ret;

	va_start(ap, n);
	tmp = NULL;
	while (n > 0)
	{
		ret = ft_matjoin(tmp, va_arg(ap, char **));
		ft_freemat(tmp);
		tmp = ret;
		n--;
	}
	return (ret);
}
