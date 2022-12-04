/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:45:05 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

unsigned int	ft_atoui(const char *nptr)
{
	unsigned int	num;

	num = 0;
	while (*nptr != '\0')
	{
		num *= 10;
		num += *nptr - 48;
		nptr++;
	}
	return (num);
}

// This function does not assume that the length of
// str is greater than or equal to INT_MAX.
ssize_t	ft_putstr(char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (-1);
	while (str[len] != '\0')
		len++;
	return (write(1, str, len));
}

void	ft_bzero(void *str, size_t size)
{
	char	*ptr;

	ptr = (char *)str;
	while (size != 0)
	{
		*ptr = 0;
		ptr++;
		size--;
	}
}

void	ft_putunbrln(unsigned int num)
{
	char	str_num[12];
	char	*str_num_ptr;

	str_num[11] = '\0';
	str_num_ptr = &str_num[10];
	while (num > 9)
	{
		*str_num_ptr-- = num % 10 + '0';
		num /= 10;
	}
	*str_num_ptr = num + '0';
	ft_putstr(str_num_ptr);
	ft_putstr("\n");
}

bool	is_only_num(char *str)
{
	while (*str != '\0')
	{
		if (!('0' <= *str && *str <= '9'))
			return (false);
		str++;
	}
	return (true);
}
