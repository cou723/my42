/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:40:27 by my_pair           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_wall(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = -1;
		while (map[i][j + 1] != '\0')
		{
			j++;
			if (map[i][j] != '0')
				continue ;
			if (i == 0 || j == 0 || !map[i + 1] || map[i - 1][j] == ' ' || map[i
				- 1][j] == '\n' || map[i + 1][j] == ' ' || map[i + 1][j] == '\n'
				|| map[i][j - 1] == ' ' || map[i][j - 1] == '\n' || map[i][j
				+ 1] == ' ' || map[i][j + 1] == '\n')
				return (false);
		}
		i++;
	}
	return (true);
}

static bool	is_map_element(char c)
{
	if (c != '0' && c != '1' && c != ' ' && c != '\n' && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E')
		return (false);
	return (true);
}

static bool	check_dup_player(char c, bool *is_exist_player)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (*is_exist_player)
			return (false);
		*is_exist_player = true;
	}
	return (true);
}

static bool	check_element(char **map)
{
	size_t	i;
	size_t	j;
	bool	is_exist_player;

	i = 0;
	is_exist_player = false;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!is_map_element(map[i][j]))
				return (false);
			if (!check_dup_player(map[i][j], &is_exist_player))
				return (false);
			j++;
		}
		i++;
	}
	if (!is_exist_player)
		return (false);
	return (true);
}

void	check_map_error(t_game *game)
{
	if (!check_wall(game->map))
		xput_error("map wall error");
	if (!check_element(game->map))
		xput_error("invalid map");
}
