/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:09:04 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/24 01:09:05 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	stack_delete(t_stack *stack, void (*del)(void *))
{
	if (del != NULL)
		del(stack->content);
	free(stack);
}

void	stack_clear(t_stack *stack, void (*del)(void *))
{
	t_stack	*tmp;
	size_t	size;
	size_t	i;

	if (stack == NULL)
		return ;
	i = 0;
	size = stack_size(stack) + 1;
	stack = stack->next;
	while (i < size)
	{
		tmp = stack->next;
		stack_delete(stack, del);
		stack = tmp;
		i++;
	}
}
