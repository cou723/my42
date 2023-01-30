/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:22:44 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/28 23:45:15 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_stack	*stack_min(t_stack *stack)
{
	return (stack_min_ignore(stack, INT_MIN));
}

t_stack	*stack_min_ignore(t_stack *stack, int ignore_max)
{
	t_stack	*min_ptr;
	int		min;

	if (stack->content == NULL && stack_size(stack) == 1)
		exit(1);
	min = INT_MAX;
	stack = stack_first(stack);
	while (stack->content != NULL)
	{
		if (stack_int(stack) < min && stack_int(stack) >= ignore_max)
		{
			min = stack_int(stack);
			min_ptr = stack;
		}
		stack = stack->next;
	}
	return (min_ptr);
}

int	stack_min_int(t_stack *stack)
{
	return (stack_int(stack_min(stack)));
}

t_stack	*stack_min_nth(t_stack *stack, size_t nth)
{
	t_stack	*nth_min;
	size_t	nth_index;
	int		ignore_max;

	ignore_max = stack_min_int(stack) + 1;
	nth_min = stack_min(stack);
	if (nth == 0)
		return (NULL);
	nth_index = nth - 1;
	while (nth_index > 0)
	{
		nth_min = stack_min_ignore(stack, ignore_max);
		ignore_max = stack_int(nth_min) + 1;
		nth_index--;
	}
	return (nth_min);
}
