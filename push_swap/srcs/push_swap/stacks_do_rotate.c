/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:07:40 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/24 01:07:44 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	do_ra(t_stack *stack, t_list **cmd_list)
{
	if (stack_size(stack) == 1)
		return ;
	stack_rotate(stack);
	add_cmd(cmd_list, ra);
}

void	do_rb(t_stack *stack, t_list **cmd_list)
{
	if (stack_size(stack) == 1)
		return ;
	stack_rotate(stack);
	add_cmd(cmd_list, rb);
}

void	do_rr(t_stacks *stacks)
{
	stack_rotate(stacks->a);
	stack_rotate(stacks->b);
	add_cmd_stacks(stacks, rr);
}
