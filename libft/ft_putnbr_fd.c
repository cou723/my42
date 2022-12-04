/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:51:35 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		is_minus;
	char	str_num[12];
	char	*str_num_ptr;

	str_num[11] = '\0';
	str_num_ptr = &str_num[10];
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		is_minus = (n < 0);
		if (is_minus)
			n = (-n);
		while (n > 9)
		{
			*str_num_ptr-- = n % 10 + '0';
			n /= 10;
		}
		*str_num_ptr = n + '0';
		if (is_minus)
			*--str_num_ptr = '-';
		ft_putstr_fd(str_num_ptr, fd);
	}
}
