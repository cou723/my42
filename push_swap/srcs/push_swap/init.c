/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:24:44 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/09/20 11:04:28 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

static void	set_stacks_func(t_stacks *stacks);

bool	set_sentry(t_stacks *stacks)
{
	stacks->a = stack_new_sentry();
	stacks->b = stack_new_sentry();
	if (stacks->a == NULL || stacks->b == NULL)
		return (false);
	return (true);
}

bool	init(int argc, const char *argv[], t_stacks *stacks)
{
	int		i;
	t_stack	*item;

	if (set_sentry(stacks) == false)
		exit(1);
	set_stacks_func(stacks);
	i = argc;
	while (i > 1)
	{
		i--;
		item = stack_new_int(ft_atoi(argv[i]));
		if (item == NULL)
			exit(1);
		stack_push(&(stacks->a), item);
	}
	stacks->cmd_list = NULL;
	return (true);
}

static void	set_stacks_func(t_stacks *stacks)
{
	stacks->a->swap = &do_sa;
	stacks->a->rotate = &do_ra;
	stacks->a->rev_rotate = &do_rra;
	stacks->a->push = &do_pa;
	stacks->b->swap = &do_sb;
	stacks->b->rotate = &do_rb;
	stacks->b->rev_rotate = &do_rrb;
	stacks->b->push = &do_pb;
}
