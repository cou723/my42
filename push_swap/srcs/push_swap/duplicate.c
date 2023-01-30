/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:07:17 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/09/20 11:08:45 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

bool	exists_duplicate_args(int argc, const char **argv)
{
	int	first;
	int	second;

	first = 1;
	while (first < argc)
	{
		second = first;
		while (second < argc)
		{
			if (first == second)
			{
				second++;
				continue ;
			}
			if (ft_strcmp(argv[first], argv[second]) == 0)
				return (false);
			second++;
		}
		first++;
	}
	return (true);
}
