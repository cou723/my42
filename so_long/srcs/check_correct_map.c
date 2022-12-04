/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:46:39 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <so_long.h>

static bool	check_invalid_character(const char **map)
{
	const char	*line;

	while (*map != NULL)
	{
		line = *map;
		while (*line != '\0')
		{
			if (*line != '0' && *line != '1' && *line != 'C' && *line != 'E'
				&& *line != 'P')
				return (put_invalid_character());
			line++;
		}
		map++;
	}
	return (true);
}

static bool	check_has_must_item(const char **map)
{
	t_must_list	must_item;

	must_item.collective = false;
	must_item.start_pos = false;
	must_item.exit = false;
	while (*map != NULL)
	{
		must_item.collective = must_item.collective | (ft_strchr(*map,
					'C') != NULL);
		must_item.start_pos = must_item.start_pos | (ft_strchr(*map,
					'P') != NULL);
		must_item.exit = must_item.exit | (ft_strchr(*map, 'E') != NULL);
		map++;
	}
	if (!(must_item.collective && must_item.start_pos && must_item.exit))
	{
		put_map_item_error_message(must_item);
		return (false);
	}
	return (true);
}

static bool	check_is_rectangle(const char **map)
{
	const char	*line;
	size_t		width;
	size_t		i;

	width = ft_strlen(*map);
	i = 0;
	while (map[i] != NULL)
	{
		line = map[i];
		if (ft_strlen(line) != width)
		{
			put_not_rectangle();
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_correct_map(const char **map)
{
	if (map == NULL)
		return (false);
	if (!(check_invalid_character(map) && check_walled(map)
			&& check_has_must_item(map) && check_is_rectangle(map)))
		return (false);
	check_warning_multiple_player(map);
	return (true);
}
