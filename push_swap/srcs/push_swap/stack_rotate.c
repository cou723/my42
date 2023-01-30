/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:09:55 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/28 17:42:00 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	stack_rotate(t_stack *stack)
{
	stack_swap_later(stack_sentry(stack)->pre);
}

void	stack_rev_rotate(t_stack *stack)
{
	stack_swap_later(stack_sentry(stack));
}

size_t	get_rotate_count(t_stack *stack, t_stack *dest)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (stack_last(stack) != dest)
	{
		stack_rotate(stack);
		count++;
	}
	while (i != count)
	{
		stack_rev_rotate(stack);
		i++;
	}
	return (count);
}

size_t	get_rev_rotate_count(t_stack *stack, t_stack *dest)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (stack_last(stack) != dest)
	{
		stack_rev_rotate(stack);
		count++;
	}
	while (i != count)
	{
		stack_rotate(stack);
		i++;
	}
	return (count);
}
