/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:09:38 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/25 20:35:44 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

size_t	stack_size(t_stack *stack)
{
	t_stack	*taken_stack;
	size_t	total;

	if (stack == NULL)
		return (0);
	taken_stack = stack;
	total = 0;
	stack = stack->next;
	while (stack != taken_stack)
	{
		total++;
		stack = stack->next;
	}
	return (total);
}

int	stack_int(t_stack *stack)
{
	return (*(int *)stack->content);
}

t_stack	*stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->content != NULL)
		stack = stack->next;
	return (stack->pre);
}

t_stack	*stack_first(t_stack *stack)
{
	return (stack_sentry(stack)->next);
}

t_stack	*stack_sentry(t_stack *stack)
{
	return (stack_last(stack)->next);
}
