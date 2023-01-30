/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:45:43 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/29 12:54:41 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void	to_small_nums(t_stack *stack)
{
	size_t	i;
	t_stack	*min;

	i = 0;
	while (i < stack_size(stack))
	{
		stack = stack_first(stack);
		min = stack_min_nth(stack, i + 1);
		while (stack->content != NULL)
		{
			if (stack == min)
				*(int *)(stack->content) = i + INT_MIN;
			stack = stack->next;
		}
		i++;
	}
	stack = stack_first(stack);
	while (stack->content != NULL)
	{
		*(int *)(stack->content) = *(int *)(stack->content) - INT_MIN;
		stack = stack->next;
	}
}

void	sort_based_on_digit(t_stack *main, t_stack *buf, t_list **cmd_list,
		size_t digit)
{
	t_stack	*stack;
	size_t	i;
	size_t	size;

	stack = stack_first(main);
	i = 0;
	size = stack_size(main);
	while (i < size)
	{
		if (!(stack_int(stack_last(stack)) >> digit & 1))
			buf->push(buf, main, cmd_list);
		else
			stack->rotate(stack, cmd_list);
		i++;
	}
	while (stack_size(buf) > 0)
		main->push(main, buf, cmd_list);
}

void	base_sorter(t_stack *nums, t_stack *buf, t_list **cmd_list)
{
	size_t	digit;
	size_t	max;

	digit = 0;
	to_small_nums(nums);
	max = get_2base_digit(stack_max_int(nums));
	while (digit < max)
	{
		sort_based_on_digit(nums, buf, cmd_list, digit);
		digit++;
	}
}
