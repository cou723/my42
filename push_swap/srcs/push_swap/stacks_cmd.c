/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:19:12 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/09/03 16:40:12 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	cmd_list_put(t_stacks stacks)
{
	t_list	*list;

	list = stacks.cmd_list;
	while (list != NULL)
	{
		cmd_put(list);
		list = list->next;
	}
}

void	cmd_put(const t_list *cmd)
{
	ft_printf("%s\n", (char *[]){"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"}[*(t_cmd *)(cmd->content)]);
}

t_cmd	*cmd_new(t_cmd cmd)
{
	t_cmd	*cmd_ptr;

	cmd_ptr = malloc(sizeof(enum e_cmd));
	if (cmd_ptr == NULL)
		return (NULL);
	*cmd_ptr = cmd;
	return (cmd_ptr);
}
