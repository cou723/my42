/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quart_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:57:42 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdbool.h>

bool	check_quart_syntax(char *line, int *exit_code)
{
	bool	is_in_q[2];

	reset_is_in_quart(is_in_q);
	while (*line != '\0')
	{
		update_quart_in(&(is_in_q[QUART_D]), &(is_in_q[QUART_S]), *line);
		line++;
	}
	if (is_in_q[QUART_D])
	{
		ft_putstr_fd("minishell: syntax error: double quote not closed\n", 2);
		*exit_code = 258;
		return (false);
	}
	if (is_in_q[QUART_S])
	{
		ft_putstr_fd("minishell: syntax error: single quote not closed\n", 2);
		*exit_code = 258;
		return (false);
	}
	return (true);
}
