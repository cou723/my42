/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:09:10 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/28 17:15:53 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

// HELP: Functions are too difficult to understand.
void	stack_swap_later(t_stack *first)
{
	t_stack	*second;
	t_stack	*pre_first;

	if (first == NULL)
		return ;
	second = first->next;
	pre_first = first->pre;
	second->pre = first->pre;
	first->pre = second;
	first->next = second->next;
	second->next = first;
	pre_first->next = second;
	first->next->pre = first;
}

void	stack_swap(t_stack *stack)
{
	stack_swap_later(stack_last(stack)->pre);
}
