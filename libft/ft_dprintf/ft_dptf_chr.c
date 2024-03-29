/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dptf_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:23:55 by abettini          #+#    #+#             */
/*   Updated: 2023/07/03 10:13:43 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftdprintf.h"

int	ft_dprint_chr(int fd, int c, t_ptf ptf)
{
	int	print_len;

	print_len = 0;
	if (!ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_dprint_special(fd, ptf.pad, ptf.pad_count - 1);
	print_len += write(fd, &c, 1);
	if (ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_dprint_special(fd, ptf.pad, ptf.pad_count - 1);
	return (print_len);
}
