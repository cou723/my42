/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxxxxx@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 07:03:32 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/09/20 12:50:06 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_splitted_count(const char **strs)
{
	int	count;

	count = 0;
	while (strs[count] != NULL)
		count++;
	return (count);
}

int	free_splitted_strs(char **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
	{
		free((void *)map[i]);
		i++;
	}
	free((void *)map);
	return (1);
}

bool	is_checker_args(int argc, const char *argv[])
{
	return (!is_correct_args(argc, argv) && argc == 2);
}

bool	set_args(int *argc, const char **argv[])
{
	char	*str;

	str = ft_strjoin("a ", (*argv)[1]);
	if (str == NULL)
		return (false);
	*argv = ((const char **)ft_split(str, ' '));
	free(str);
	*argc = get_splitted_count(*argv);
	if (*argv == NULL)
		return (false);
	return (true);
}
