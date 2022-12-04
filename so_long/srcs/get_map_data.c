/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:15:34 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libft.h>
#include <so_long.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

static void	*terminate_error(int fd)
{
	perror("so_long");
	put_error();
	close(fd);
	return (NULL);
}

static bool	check_null(char *line, int fd)
{
	if (line != NULL)
		return (true);
	close(fd);
	put_error();
	put_error_message(MAP_IS_EMPTY);
	return (false);
}

static bool	check_contain_blank_line(char *map_text, int fd)
{
	size_t	i;

	i = 0;
	while (map_text[i + 2] != '\0')
	{
		if (map_text[i + 0] == '\n' && map_text[i + 1] == '\n')
		{
			close(fd);
			free(map_text);
			put_error();
			put_error_message(MAP_CONTAIN_BLANK_LINE);
			return (false);
		}
		i++;
	}
	return (true);
}

static char	*get_map_str(int fd)
{
	char	*map_text;
	char	*line;
	char	*tmp;

	map_text = NULL;
	line = get_next_line(fd);
	if (!check_null(line, fd))
		return (NULL);
	while (line != NULL)
	{
		tmp = ft_strjoin_null_allowable(map_text, line);
		free(line);
		free(map_text);
		if (tmp == NULL)
			return (terminate_error(fd));
		map_text = tmp;
		line = get_next_line(fd);
	}
	if (!check_contain_blank_line(map_text, fd))
		return (NULL);
	close(fd);
	return (map_text);
}

const char	**get_map_data(int fd)
{
	char	*map_text;
	char	**map;

	if (fd == -1)
		return (NULL);
	map_text = get_map_str(fd);
	if (map_text == NULL)
		return (NULL);
	if (*map_text == '\n')
	{
		put_not_rectangle_or_empty();
		return (NULL);
	}
	map = ft_split(map_text, '\n');
	free(map_text);
	if (map == NULL)
	{
		put_error();
		perror("so_long");
		return (NULL);
	}
	return ((const char **)map);
}
