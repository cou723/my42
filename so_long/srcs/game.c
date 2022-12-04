/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:48:41 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <mlx.h>
#include <so_long.h>
#include <stddef.h>
#include <stdio.h>

void	run_game(const char **map)
{
	t_game	game;

	if (!init_game(&game, map))
	{
		free(game.mlx);
		return ;
	}
	mlx_key_hook(game.win, key_press, &game);
	mlx_hook(game.win, 17, (1L << 17), &win_close, &game);
	mlx_hook(game.win, 19, (1L << 19), &win_show, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	free_game_map(game.mlx, game.map);
	free_player(game.mlx, game.player);
	free(game.mlx);
}
