/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:08:56 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/27 13:40:11 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_stack	*stack_get(t_stack *stack, size_t need_i)
{
	size_t	index;
	t_stack	*stack_ptr;

	if (stack == NULL)
		return (NULL);
	stack_ptr = stack;
	index = 0;
	need_i++;
	while (index < need_i)
	{
		stack_ptr = stack_ptr->next;
		index++;
	}
	if (stack_ptr->content == NULL)
		stack_ptr = stack_ptr->next;
	return (stack_ptr);
}
