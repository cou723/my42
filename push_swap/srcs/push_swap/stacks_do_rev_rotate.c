/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:08:08 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/24 01:08:10 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	do_rra(t_stack *stack, t_list **cmd_list)
{
	stack_rev_rotate(stack);
	add_cmd(cmd_list, rra);
}

void	do_rrb(t_stack *stack, t_list **cmd_list)
{
	stack_rev_rotate(stack);
	add_cmd(cmd_list, rrb);
}

void	do_rrr(t_stacks *stacks)
{
	stack_rev_rotate(stacks->a);
	stack_rev_rotate(stacks->b);
	add_cmd_stacks(stacks, rrr);
}
