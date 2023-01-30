/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:17:06 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/09/15 15:19:40 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdbool.h>
#include <unistd.h>

bool	is_only_num(const char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

size_t	int_digit(int num)
{
	size_t	digit;

	digit = 0;
	if (num == INT_MIN)
		num++;
	if (num < 0)
	{
		digit++;
		num *= -1;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		digit++;
		num /= 10;
	}
	return (digit);
}

size_t	get_2base_digit(int num)
{
	size_t	digit;

	digit = 0;
	while (num > 0)
	{
		num = num >> 1;
		digit++;
	}
	return (digit);
}

bool	is_sorted(t_stack *stack)
{
	bool	is_sort;

	is_sort = true;
	stack = stack_first(stack);
	while (stack->next->content != NULL)
	{
		is_sort = is_sort & (stack_int(stack) > stack_int(stack->next));
		stack = stack->next;
	}
	return (is_sort);
}
