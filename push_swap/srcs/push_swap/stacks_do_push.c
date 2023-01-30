/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:08:02 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/08/28 17:28:32 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	do_pa(t_stack *to, t_stack *from, t_list **cmd_list)
{
	stack_push(&(to), stack_pop(from));
	add_cmd(cmd_list, pa);
}

void	do_pb(t_stack *to, t_stack *from, t_list **cmd_list)
{
	stack_push(&(to), stack_pop(from));
	add_cmd(cmd_list, pb);
}
