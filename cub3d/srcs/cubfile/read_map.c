/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_pair <my_pair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:40:37 by my_pair           #+#    #+#             */
/*   Updated: 2022/12/04 15:36:52 by my_pair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**create_new_buf(char **old_buf, size_t len)
{
	size_t	i;
	char	**new_buf;

	i = 0;
	new_buf = wcalloc(len + 1, sizeof(char *));
	while (old_buf && old_buf[i])
	{
		new_buf[i] = old_buf[i];
		i ++;
	}
	if (old_buf)
		free(old_buf);
	return (new_buf);
}

void	read_map(int fd, t_game *game)
{
	char	*line;
	char	**buf;
	size_t	len;

	len = 0;
	buf = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			xput_error("invalid map");
		if (line[0] != '\n')
			break ;
	}
	while (1)
	{
		len ++;
		if (line == NULL)
			break ;
		buf = create_new_buf(buf, len);
		buf[len - 1] = line;
		buf[len] = NULL;
		game->map = buf;
		line = get_next_line(fd);
	}
}
