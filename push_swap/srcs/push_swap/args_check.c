/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:07:29 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/28 17:42:28 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

static bool	args_test(int argc, const char **argv, bool (*f)(const char *))
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!f(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_num_args(int argc, const char **argv)
{
	return (args_test(argc, argv, is_only_num));
}

bool	can_atoi_args(int argc, const char **argv)
{
	return (args_test(argc, argv, can_atoi));
}

bool	can_atoi(const char *num_str)
{
	if (ft_strlen(num_str) > int_digit(INT_MIN))
		return (false);
	if (ft_atoli(num_str) > INT_MAX || ft_atoli(num_str) < INT_MIN)
		return (false);
	return (true);
}
