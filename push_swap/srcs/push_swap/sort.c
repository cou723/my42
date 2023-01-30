/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:33:20 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/09/20 11:57:40 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void	sort_two_numbers(t_stack *stack, t_list **cmd_list);
void	sort_three_numbers(t_stack *stack, t_list **cmd_list);
void	sort_three_to_six(t_stack *nums, t_stack *buf, t_list **cmd_list);
void	sort_less_than_three(t_stack *stack, t_list **cmd_list);

void	sort(t_stack *a, t_stack *b, t_list **cmd_list)
{
	if (is_sorted(a))
		return ;
	if (stack_size(a) <= 3)
		sort_less_than_three(a, cmd_list);
	else if (stack_size(a) <= 6)
		sort_three_to_six(a, b, cmd_list);
	else
		base_sorter(a, b, cmd_list);
	return ;
}

void	sort_less_than_three(t_stack *nums, t_list **cmd_list)
{
	if (stack_size(nums) <= 1)
		return ;
	else if (stack_size(nums) == 2)
		sort_two_numbers(nums, cmd_list);
	else if (stack_size(nums) == 3)
		sort_three_numbers(nums, cmd_list);
}

void	sort_three_to_six(t_stack *nums, t_stack *buf, t_list **cmd_list)
{
	while (stack_size(nums) != 3)
	{
		shortest_rotate(nums, stack_min(nums), cmd_list);
		buf->push(buf, nums, cmd_list);
	}
	sort_three_numbers(nums, cmd_list);
	while (stack_size(buf) != 0)
		nums->push(nums, buf, cmd_list);
}

void	sort_two_numbers(t_stack *nums, t_list **cmd_list)
{
	int	first;
	int	second;

	first = stack_int(stack_get(nums, 0));
	second = stack_int(stack_get(nums, 1));
	if (first < second)
		nums->swap(nums, cmd_list);
}

void	sort_three_numbers(t_stack *nums, t_list **cmd_list)
{
	int	first;
	int	second;
	int	third;

	first = stack_int(stack_get(nums, 0));
	second = stack_int(stack_get(nums, 1));
	third = stack_int(stack_get(nums, 2));
	if (first > second && second > third)
		return ;
	else if (first > third && third > second)
		nums->swap(nums, cmd_list);
	else if (third > second && second > first)
	{
		nums->swap(nums, cmd_list);
		nums->rev_rotate(nums, cmd_list);
	}
	else if (third > first && first > second)
		nums->rotate(nums, cmd_list);
	else if (second > first && first > third)
	{
		nums->swap(nums, cmd_list);
		nums->rotate(nums, cmd_list);
	}
	else if (second > third && third > first)
		nums->rev_rotate(nums, cmd_list);
}
