/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:59:04 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/18 18:25:03 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_ft_printf.h"

size_t	put_nbr(int output)
{
	return (ft_putnbr_fd(output, 1));
}

size_t	put_address(size_t output)
{
	size_t	total;

	total = put_str("0x");
	return (put_u_nbr_base((size_t)output, "0123456789abcdef") + total);
}

size_t	put_u_nbr_base(size_t n, const char *letters)
{
	unsigned int	base;
	size_t			n_digit;
	size_t			total;

	total = 0;
	base = strlen(letters);
	n_digit = get_digit(n, base);
	while (n_digit > 0)
	{
		total += ft_putchar_fd(letters[n / n_digit], 1);
		n %= n_digit;
		n_digit /= base;
	}
	return (total);
}

size_t	get_digit(size_t n, unsigned int base)
{
	size_t	n_digit;

	n_digit = 1;
	while (n / n_digit >= base)
		n_digit *= base;
	return (n_digit);
}
