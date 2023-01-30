/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_optimaze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:06:39 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/28 17:26:23 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

static void	merge_cmd(t_list *cmd_list);
static void	remove_rotate_duplicate(t_list *cmd_list);

void	cmd_optimize(t_list *cmd_list)
{
	t_list	*head;

	if (cmd_list == NULL || cmd_list->next == NULL)
		return ;
	merge_cmd(cmd_list);
	if (ft_lstsize(cmd_list) < 4)
		return ;
	head = cmd_list;
	while (cmd_list->next->next->next != NULL)
	{
		if ((*(t_cmd *)(cmd_list->next->content) == ra
			&& *(t_cmd *)(cmd_list->next->next->content) == rra)
			|| (*(t_cmd *)(cmd_list->next->content) == rb
			&& *(t_cmd *)(cmd_list->next->next->content) == rrb))
		{
			remove_rotate_duplicate(cmd_list);
			cmd_list = head;
		}
		else
			cmd_list = cmd_list->next;
	}
}

static void	merge_cmd(t_list *cmd_list)
{
	t_cmd	cmd;
	t_cmd	next;

	while (cmd_list->next->next != NULL)
	{
		cmd = *(t_cmd *)(cmd_list->content);
		next = *(t_cmd *)(cmd_list->next->content);
		if ((cmd == sa && next == sb) || (cmd == sb && next == sa))
		{
			cmd_list->next = cmd_list->next->next;
			*(t_cmd *)(cmd_list->content) = ss;
		}
		else if ((cmd == ra && next == rb) || (cmd == rb && next == ra))
		{
			cmd_list->next = cmd_list->next->next;
			*(t_cmd *)(cmd_list->content) = rr;
		}
		else if ((cmd == rra && next == rrb) || (cmd == rrb && next == rra))
		{
			cmd_list->next = cmd_list->next->next;
			*(t_cmd *)(cmd_list->content) = rrr;
		}
		cmd_list = cmd_list->next;
	}
}

static void	remove_rotate_duplicate(t_list *cmd_list)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*fourth;

	if (cmd_list == NULL || cmd_list->next == NULL
		|| cmd_list->next->next == NULL || cmd_list->next->next->next == NULL)
		return ;
	first = cmd_list;
	second = cmd_list->next;
	third = cmd_list->next->next;
	fourth = cmd_list->next->next->next;
	ft_lstdelone(second, free);
	ft_lstdelone(third, free);
	first->next = fourth;
}
