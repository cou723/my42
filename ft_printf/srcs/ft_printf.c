/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:04:51 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/18 14:49:38 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_ft_printf.h"

static size_t	variable_output(char specifier, va_list output_ap);

// int	ft_printf(const char *format, ...)
// {
// 	va_list	ap;
// 	size_t	total;

// 	va_start(ap, format);
// 	total = 0;
// 	while (*format != '\0')
// 	{
// 		if (*format == '%')
// 		{
// 			total += variable_output(*(format + 1), ap);
// 			format++;
// 		}
// 		else
// 			total += put_char(*format);
// 		format++;
// 	}
// 	va_end(ap);
// 	return (total);
// }

static size_t	variable_output(char specifier, va_list output_ap)
{
	size_t	printed_length;

	printed_length = 0;
	if (specifier == 'c')
		printed_length = put_char(va_arg(output_ap, int));
	else if (specifier == 's')
		printed_length = put_str(va_arg(output_ap, char *));
	else if (specifier == 'p')
		printed_length = put_address((size_t)va_arg(output_ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		printed_length = put_nbr(va_arg(output_ap, int));
	else if (specifier == 'u')
		printed_length = put_u_nbr_base(va_arg(output_ap, unsigned int),
				"0123456789");
	else if (specifier == 'x')
		printed_length = put_u_nbr_base(va_arg(output_ap, unsigned int),
				"0123456789abcdef");
	else if (specifier == 'X')
		printed_length = put_u_nbr_base(va_arg(output_ap, unsigned int),
				"0123456789ABCDEF");
	else if (specifier == '%')
		printed_length = put_char('%');
	return (printed_length);
}
