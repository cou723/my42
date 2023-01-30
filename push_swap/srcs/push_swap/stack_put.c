/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:08:29 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/09/07 13:10:38 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	stack_put_str(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (1)
	{
		if (stack->content == NULL)
			ft_printf("[%p] pre:%p, content:(null), next:%p \n",
				stack,
				stack->pre,
				stack->next);
		else
			ft_printf("[%p] pre:%p, content:%s, next:%p \n",
				stack,
				stack->pre,
				stack->content,
				stack->next);
		stack = stack->next;
		if (stack == tmp)
			break ;
	}
}

void	stack_put_int(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (1)
	{
		if (stack->content == NULL)
			ft_printf("[%p] pre:%p, content:(null), next:%p \n",
				stack,
				stack->pre,
				stack->next);
		else
			ft_printf("[%p] pre:%p, content:%d, next:%p \n",
				stack,
				stack->pre,
				*(int *)(stack->content),
				stack->next);
		stack = stack->next;
		if (stack == tmp)
			break ;
	}
}

void	stack_put_content_int(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	ft_printf("[ ");
	while (1)
	{
		if (stack->content == NULL)
			ft_printf("null, ");
		else
			ft_printf("%d, ", stack_int(stack));
		stack = stack->next;
		if (stack == tmp)
			break ;
	}
	ft_printf("\b\b");
	ft_printf(" ]");
}
