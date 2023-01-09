/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:37:14 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <philo.h>
#include <stdbool.h>
#include <stddef.h>

size_t	get_digit(size_t n)
{
	size_t	n_digit;

	n_digit = 1;
	while (n / n_digit >= 10)
		n_digit *= 10;
	return (n_digit);
}

bool	is_only_num(const char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	is_overflow(char *num)
{
	return (ft_strlen(num) > get_digit(UINT_MAX) && ft_atoli(num) > UINT_MAX);
}

bool	can_to_uint(char *num)
{
	if (num[0] == '0' && num[1] == '\0')
		return (true);
	return (!is_overflow(num) && is_only_num(num) && num[0] != '0');
}

bool	is_correct_args(int argc, char *argv[])
{
	bool	is_correct_argc;
	bool	can_must_to_uint;
	bool	can_optional_to_uint;

	is_correct_argc = (argc == 5 || argc == 6);
	if (!is_correct_argc)
		return (false);
	can_must_to_uint = (can_to_uint(argv[1]) && can_to_uint(argv[2])
			&& can_to_uint(argv[3]) && can_to_uint(argv[4]));
	can_optional_to_uint = (argc == 5 || can_to_uint(argv[5]));
	if (!(can_must_to_uint && can_optional_to_uint))
		put_str(USAGE);
	return (can_must_to_uint && can_optional_to_uint);
}
