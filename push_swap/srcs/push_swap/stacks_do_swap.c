/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:08:37 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/24 02:14:35 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	do_sa(t_stack *stack, t_list **cmd_list)
{
	stack_swap(stack_last(stack)->pre);
	add_cmd(cmd_list, sa);
}

void	do_sb(t_stack *stack, t_list **cmd_list)
{
	stack_swap(stack_last(stack)->pre);
	add_cmd(cmd_list, sb);
}

void	do_ss(t_stacks *stacks)
{
	stack_swap(stack_last(stacks->a)->pre);
	stack_swap(stack_last(stacks->b)->pre);
	add_cmd_stacks(stacks, ss);
}
