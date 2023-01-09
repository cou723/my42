/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:08:38 by *******           #+#    #+#             */
/*   Updated: 2022/12/04 16:08:38 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->n_img.img);
	mlx_destroy_image(game->mlx, game->s_img.img);
	mlx_destroy_image(game->mlx, game->w_img.img);
	mlx_destroy_image(game->mlx, game->e_img.img);
	mlx_destroy_image(game->mlx, game->screen.img);
}

// TODO: It's not good to let the EXIT do all the FREE
int	destroy_and_exit(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	mlx_destroy_window(game->mlx, game->win);
	destroy_images(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	key_press_hook(int key_code, t_game *game)
{
	if (key_code == KC_W)
		game->move_relative_dir = UP;
	if (key_code == KC_A)
		game->move_relative_dir = LEFT;
	if (key_code == KC_S)
		game->move_relative_dir = DOWN;
	if (key_code == KC_D)
		game->move_relative_dir = RIGHT;
	if (key_code == KC_LEFT)
		game->rotate_relative_dir = LEFT;
	if (key_code == KC_RIGHT)
		game->rotate_relative_dir = RIGHT;
	if (key_code == KC_ESC)
		destroy_and_exit((void *)game);
	return (0);
}

int	key_release_hook(int key_code, t_game *game)
{
	if (key_code == KC_W || key_code == KC_A || key_code == KC_S
		|| key_code == KC_D)
		game->move_relative_dir = NONE;
	if (key_code == KC_LEFT || key_code == KC_RIGHT)
		game->rotate_relative_dir = NONE;
	return (0);
}
