/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ******* <*******@student.42tokyo.jp>             +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2022/12/04 15:17:43 by *******           #+#    #+#             */
/*   Updated: 2022/12/04 15:17:43 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	move_player(t_game *game);
static void	rotate_player(t_game *game, t_relative_dir side);

void	update_player(t_game *game)
{
	move_player(game);
	rotate_player(game, game->rotate_relative_dir);
}

static void	add_player_pos(t_game *g, double x, double y)
{
	g->player_pos_x += (x * PLAYER_MOVE_SPEED);
	g->player_pos_y += (y * PLAYER_MOVE_SPEED);
	if (g->map[(int)floor(g->player_pos_y)][(int)floor(g->player_pos_x)] == '1')
	{
		g->player_pos_x -= (x * PLAYER_MOVE_SPEED);
		g->player_pos_y -= (y * PLAYER_MOVE_SPEED);
	}
}

// Note : In this world the y-axis is positive downward.
static void	move_player(t_game *g)
{
	if (g->move_relative_dir == NONE)
		return ;
	if (g->move_relative_dir == UP)
		add_player_pos(g, g->player_dir_x, -g->player_dir_y);
	if (g->move_relative_dir == DOWN)
		add_player_pos(g, -g->player_dir_x, g->player_dir_y);
	if (g->move_relative_dir == LEFT)
		add_player_pos(g, -g->player_dir_y, -g->player_dir_x);
	if (g->move_relative_dir == RIGHT)
		add_player_pos(g, g->player_dir_y, g->player_dir_x);
}

// TODO: lodev's roundup: understanding required
static void	rotate_player(t_game *g, t_relative_dir side)
{
	double	old_player_dir_x;
	double	old_camera_plane_dir_x;
	double	radian;

	if (side == NONE)
		return ;
	if (side == LEFT)
		radian = PLAYER_ROTATE_SPEED;
	else
		radian = -PLAYER_ROTATE_SPEED;
	old_player_dir_x = g->player_dir_x;
	g->player_dir_x = g->player_dir_x * cos(radian) - g->player_dir_y
		* sin(radian);
	g->player_dir_y = old_player_dir_x * sin(radian) + g->player_dir_y
		* cos(radian);
	old_camera_plane_dir_x = g->camera_plane_dir_x;
	g->camera_plane_dir_x = g->camera_plane_dir_x * cos(radian)
		- g->camera_plane_dir_y * sin(radian);
	g->camera_plane_dir_y = old_camera_plane_dir_x * sin(radian)
		+ g->camera_plane_dir_y * cos(radian);
}
