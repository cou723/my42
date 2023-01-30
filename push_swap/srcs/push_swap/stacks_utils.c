/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:08:16 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/09/20 12:48:29 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	add_cmd_stacks(t_stacks *stacks, t_cmd cmd)
{
	add_cmd(&(stacks->cmd_list), cmd);
}

void	add_cmd(t_list **cmd_list, t_cmd cmd)
{
	t_cmd	*cmd_ptr;

	cmd_ptr = malloc(sizeof(enum e_cmd));
	if (cmd_ptr == NULL)
		return ;
	*cmd_ptr = cmd;
	ft_lstadd_back(cmd_list, ft_lstnew(cmd_ptr));
}

void	shortest_rotate(t_stack *stack, t_stack *want_head, t_list **cmd_list)
{
	size_t	rotate_count;
	size_t	rev_rotate_count;

	if (stack == want_head)
		return ;
	rotate_count = get_rotate_count(stack, want_head);
	rev_rotate_count = get_rev_rotate_count(stack, want_head);
	if (rotate_count < rev_rotate_count)
	{
		while (rotate_count != 0)
		{
			stack->rotate(stack, cmd_list);
			rotate_count--;
		}
	}
	else
	{
		while (rev_rotate_count != 0)
		{
			stack->rev_rotate(stack, cmd_list);
			rev_rotate_count--;
		}
	}
}
