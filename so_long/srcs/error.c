/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:48:49 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <so_long.h>
#include <stddef.h>
#include <stdio.h>
#include <ft_printf.h>

void	put_error_message(const char *error_message)
{
	int		write_len;
	size_t	retry_count;

	retry_count = 10;
	write_len = -1;
	while (write_len == -1 && retry_count > 0)
	{
		write_len = ft_printf((char *)error_message);
		retry_count--;
	}
}

void	put_error(void)
{
	put_error_message(ERROR_MESSAGE);
}

void	put_usage(void)
{
	put_error_message(USAGE);
}

void	put_not_ber_file(const char *filename)
{
	put_error();
	ft_printf("'%s' is not .ber file.\n", filename);
	put_usage();
}
