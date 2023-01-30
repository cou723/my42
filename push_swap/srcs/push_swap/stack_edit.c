/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_edit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:11:01 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/25 20:43:44 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void	inherit_funcs(t_stack *stack, t_stack *new_stack);

void	stack_push(t_stack **stack, t_stack *push)
{
	t_stack	*last;
	t_stack	*sentry;

	if (*stack == NULL)
		*stack = push;
	if (push == NULL)
		return ;
	last = stack_last(*stack);
	sentry = stack_sentry(*stack);
	push->pre = last;
	push->next = sentry;
	sentry->pre = push;
	last->next = push;
	inherit_funcs(sentry, push);
}

static void	inherit_funcs(t_stack *stack, t_stack *new_stack)
{
	new_stack->swap = stack->swap;
	new_stack->rotate = stack->rotate;
	new_stack->rev_rotate = stack->rev_rotate;
	new_stack->push = stack->push;
}

t_stack	*stack_pop(t_stack *stack)
{
	t_stack	*last_item;
	t_stack	*sentry;

	if (stack == NULL)
		return (NULL);
	last_item = stack_last(stack);
	last_item->pre->next = stack_sentry(stack);
	sentry = stack_sentry(stack);
	sentry->pre = last_item->pre;
	return (last_item);
}
