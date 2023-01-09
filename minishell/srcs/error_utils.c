/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:30:39 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char	**check_malloc_strs(char **strs)
{
	if (strs == NULL)
	{
		perror(MINISHELL);
		exit(STATUS_FAILS);
	}
	return (strs);
}

char	*wrap_malloc(char *str)
{
	if (str == NULL)
	{
		perror(MINISHELL);
		exit(STATUS_FAILS);
	}
	return (str);
}

t_false	export_error(char *args)
{
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd(args, 2);
	ft_putstr_fd(" : not a valid identifier\n", 2);
	return (false);
}
