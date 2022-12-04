/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:47:25 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>

static void	try_move(t_game *game, int to_x, int to_y)
{
	static size_t	move_count = 0;
	t_pos			*pos;
	const char		**map;

	pos = &(game->player->pos);
	map = (const char **)game->map->map;
	if (map[pos->y + to_y][pos->x + to_x] != WALL)
	{
		if (map[pos->y][pos->x] == 'C')
		{
			game->map->map[pos->y][pos->x] = '0';
			game->map->collective_count--;
		}
		display_map_tile(game, map[pos->y][pos->x], pos->x, pos->y);
		pos->x += to_x;
		pos->y += to_y;
		update_player(game);
		put_count(++move_count);
		if (map[pos->y][pos->x] == EXIT && game->map->collective_count == 0)
		{
			win_close(game);
			return ;
		}
	}
}

void	try_move_up(t_game *game)
{
	try_move(game, 0, -1);
}

void	try_move_down(t_game *game)
{
	try_move(game, 0, 1);
}

void	try_move_left(t_game *game)
{
	try_move(game, -1, 0);
}

void	try_move_right(t_game *game)
{
	try_move(game, 1, 0);
}
