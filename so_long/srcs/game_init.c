/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:48:15 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>
#include <stdio.h>
#include <stdlib.h>
#include <libft.h>

static void	set_player_pos(const char **map, t_player *player)
{
	int		x;
	int		y;
	bool	is_brk;

	x = 0;
	y = 0;
	is_brk = false;
	while (map[y] != NULL && !is_brk)
	{
		x = 0;
		while (map[y][x] != '\0' && !is_brk)
		{
			if (map[y][x] == 'P')
			{
				player->pos.x = x;
				player->pos.y = y;
				is_brk = true;
			}
			x++;
		}
		y++;
	}
}

static bool	init_player(t_game *game)
{
	int	dummy;

	game->player = malloc(sizeof(t_player));
	if (game->player == NULL)
		return (false);
	set_player_pos((const char **)game->map->map, game->player);
	game->player->img = mlx_xpm_file_to_image(game->mlx, "img/player.xpm",
			&dummy, &dummy);
	if (game->player->img == NULL)
	{
		free(game->player);
		return (false);
	}
	return (true);
}

static size_t	get_collective_count(const char **map)
{
	size_t	count;
	int		x;
	int		y;

	count = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static bool	init_map(t_game *game, const char **map)
{
	int	dummy;

	dummy = 0;
	game->map = malloc(sizeof(t_map));
	if (game->map == NULL)
		return (false);
	game->map->map = (char **)map;
	game->map->wall_img = mlx_xpm_file_to_image(game->mlx, "img/wall_block.xpm",
			&dummy, &dummy);
	game->map->void_img = mlx_xpm_file_to_image(game->mlx, "img/void.xpm",
			&dummy, &dummy);
	game->map->collective_img = mlx_xpm_file_to_image(game->mlx,
			"img/collective.xpm", &dummy, &dummy);
	game->map->exit_img = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm",
			&dummy, &dummy);
	if (game->map->wall_img == NULL || game->map->collective_img == NULL
		|| game->map->exit_img == NULL || game->map->void_img == NULL)
	{
		free_game_map(game->mlx, game->map);
		return (false);
	}
	game->map->collective_count = get_collective_count(map);
	return (true);
}

bool	init_game(t_game *game, const char **map)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL || !init_map(game, map))
	{
		perror("so_long");
		return (false);
	}
	game->win = mlx_new_window(game->mlx, (int)ft_strlen(map[0]) * IMAGE_WIDTH,
			get_map_height(map) * IMAGE_WIDTH, "./so_long");
	if (game->win == NULL)
		return (false);
	if (!init_player(game))
	{
		perror("so_long");
		mlx_destroy_window(game->mlx, game->win);
		free_game_map(game->mlx, game->map);
		return (false);
	}
	return (true);
}
