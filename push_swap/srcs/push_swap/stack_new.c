/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:09:07 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/25 20:34:34 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_stack	*stack_new(void *content)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->pre = NULL;
	stack->content = content;
	stack->next = NULL;
	return (stack);
}

t_stack	*stack_new_int(int nbr)
{
	t_stack	*stack;
	int		*p;

	p = malloc(sizeof(int));
	if (p == NULL)
		return (NULL);
	*p = nbr;
	stack = stack_new(p);
	return (stack);
}

t_stack	*stack_new_sentry(void)
{
	t_stack	*stack;

	stack = stack_new(NULL);
	if (stack == NULL)
		return (NULL);
	stack->next = stack;
	stack->pre = stack;
	return (stack);
}
