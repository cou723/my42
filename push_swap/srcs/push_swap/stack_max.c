/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:42:30 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/28 17:34:33 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_stack	*stack_max(t_stack *stack)
{
	t_stack	*max_ptr;
	int		max;

	if (stack->content == NULL && stack_size(stack) == 1)
		exit(1);
	max = INT_MIN;
	stack = stack_first(stack);
	while (stack->content != NULL)
	{
		if (stack_int(stack) > max)
		{
			max = stack_int(stack);
			max_ptr = stack;
		}
		stack = stack->next;
	}
	return (max_ptr);
}

int	stack_max_int(t_stack *stack)
{
	return (stack_int(stack_max(stack)));
}
