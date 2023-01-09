/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:31:10 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

bool	put_redirect_to_error(char *filename)
{
	if (ft_putstr_fd("minishell: ", 2) == -1)
		perror("minishell");
	else
		perror(filename);
	return (false);
}

bool	redirect_to(char *to_path)
{
	int	fd;

	fd = open(to_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (put_redirect_to_error(to_path));
	if (dup2(fd, STDOUT) == -1)
		return (put_redirect_to_error(to_path));
	close(fd);
	return (true);
}
