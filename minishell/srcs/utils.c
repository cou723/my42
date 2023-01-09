/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:31:19 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "minishell.h"

// strcmp's wrapper
bool	strequ(char *a, char *b)
{
	return (ft_strcmp(a, b) == 0);
}

bool	exist_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

// must null check
char	*path_concat(char *dir, char *file)
{
	char	*path;

	dir = ft_strjoin(dir, "/");
	if (dir == NULL)
		return (NULL);
	path = ft_strjoin(dir, file);
	free(dir);
	if (path == NULL)
		return (NULL);
	return (path);
}

// This function doesn't return.
void	*put_error_exit(void)
{
	perror(MINISHELL);
	exit(STATUS_FAILS);
}
