/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_pair <my_pair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:40:20 by my_pair           #+#    #+#             */
/*   Updated: 2022/12/04 14:40:33 by my_pair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	input_nswe(t_game *game, char *line)
{
	*ft_strchr(line, '\n') = '\0';
	if (line[0] == 'N')
	{
		if ((line[1] != 'O' && line[2] != ' ') || game->config.n_path)
			xput_error("invalid config element");
		game->config.n_path = &line[3];
	}
	if (line[0] == 'S')
	{
		if ((line[1] != 'O' && line[2] != ' ') || game->config.s_path)
			xput_error("invalid config element");
		game->config.s_path = &line[3];
	}
	if (line[0] == 'W')
	{
		if ((line[1] != 'E' && line[2] != ' ') || game->config.w_path)
			xput_error("invalid config element");
		game->config.w_path = &line[3];
	}
	if (line[0] == 'E')
	{
		if ((line[1] != 'A' && line[2] != ' ') || game->config.e_path)
			xput_error("invalid config element");
		game->config.e_path = &line[3];
	}
}

static void	input_color(t_game *game, char *line, char type)
{
	size_t	i;
	size_t	j;
	int		num;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (line[j] >= '0' && line[j] <= '9')
			j++;
		line[j] = '\0';
		num = ft_atoi(line);
		if (num < 0 || num > 255)
			xput_error("invalid color number");
		if (type == 'f')
			game->config.floor_color[i] = num;
		if (type == 'c')
			game->config.ceiling_color[i] = num;
		j++;
		line = &line[j];
		i++;
	}
	if (line[0] != '\0')
		xput_error("invalid config element");
}

static void	input_config(t_game *game, char *line)
{
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
		input_nswe(game, line);
	if (line[0] == 'F')
	{
		if (line[1] != ' ')
			xput_error("invalid config element");
		input_color(game, &line[2], 'f');
	}
	if (line[0] == 'C')
	{
		if (line[1] != ' ')
			xput_error("invalid config element");
		input_color(game, &line[2], 'c');
	}
}

void	read_config(int fd, t_game *game)
{
	t_config	*config;
	char		*line;
	char		c;

	config = &game->config;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			xput_error("NULL config");
		c = line[0];
		if (config->n_path && config->s_path && config->w_path && config->e_path
			&& config->floor_color[0] != -1 && config->ceiling_color[0] != -1)
			break ;
		if (c == '\n')
			continue ;
		if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != 'F'
			&& c != 'C')
			xput_error("invalid config element");
		input_config(game, line);
	}
}
