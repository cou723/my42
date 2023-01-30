/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:07:32 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/09/20 12:50:06 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void	run_push_swap(t_stacks *stacks);
int		error_process(bool checker_mode, char **strs);
bool	set_for_checker(int *argc, const char **argv[]);

int	main(int argc, const char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	if (set_for_checker(&argc, &argv) == false)
		exit(1);
	if (!is_correct_args(argc, argv))
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(1);
	}
	init(argc, argv, &stacks);
	run_push_swap(&stacks);
	cmd_optimize(stacks.cmd_list);
	cmd_list_put(stacks);
	exit(0);
}

bool	set_for_checker(int *argc, const char **argv[])
{
	if (is_checker_args(*argc, *argv))
	{
		if (set_args(argc, argv) == false)
			return (false);
	}
	return (true);
}

bool	is_correct_args(int argc, const char *argv[])
{
	if (argc == 1)
		return (false);
	if (!is_num_args(argc, argv))
		return (false);
	if (!can_atoi_args(argc, argv))
		return (false);
	if (!exists_duplicate_args(argc, argv))
		return (false);
	return (true);
}

void	run_push_swap(t_stacks *stacks)
{
	sort(stacks->a, stacks->b, &(stacks->cmd_list));
}

int	error_process(bool checker_mode, char **strs)
{
	if (checker_mode)
		free_splitted_strs(strs);
	return (1);
}
