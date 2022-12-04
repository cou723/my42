/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 03:56:31 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/18 18:19:05 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_ft_printf.h"

size_t	put_char(char output)
{
	return (ft_putchar_fd(output, 1));
}

size_t	put_str(char *output)
{
	if (output == NULL)
		return (put_str("(null)"));
	return (ft_putstr_fd(output, 1));
}
