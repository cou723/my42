/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:54:30 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <so_long.h>
#include <stddef.h>
#include <libft.h>

static bool	check_only_wall(const char *line)
{
	while (*line != '\0')
	{
		if (*line != WALL)
		{
			put_map_not_walled_in();
			return (false);
		}
		line++;
	}
	return (true);
}

static bool	check_wall_both_sides(const char *line)
{
	if ((line[0] == WALL && line[ft_strlen(line) - 1] == WALL))
		return (true);
	put_map_not_walled_in();
	return (false);
}

bool	check_walled(const char **map)
{
	const char	*line;
	size_t		height;
	size_t		i;

	height = get_map_height(map);
	i = 0;
	while (i < height)
	{
		line = map[i];
		if (i == 0 || i == height - 1)
		{
			if (!check_only_wall(line))
				return (false);
		}
		else
		{
			if (!check_wall_both_sides(line))
				return (false);
		}
		i++;
	}
	return (true);
}
