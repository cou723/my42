/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:48:44 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>

static void	operate_player(int keycode, t_game *game)
{
	if (keycode == 'w')
		try_move_up(game);
	else if (keycode == 's')
		try_move_down(game);
	else if (keycode == 'd')
		try_move_right(game);
	else if (keycode == 'a')
		try_move_left(game);
}

int	win_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	key_press(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 65307)
		win_close(game);
	else if (key == 'w' || key == 'd' || key == 's' || key == 'a')
		operate_player(key, game);
	return (0);
}

int	win_show(t_game *game)
{
	display_map(game);
	display_sprite(game, game->player->pos.x, game->player->pos.y,
		game->player->img);
	return (0);
}
