/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_pair <my_pair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:41:02 by my_pair           #+#    #+#             */
/*   Updated: 2022/12/04 14:41:04 by my_pair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_ply_dir(t_game *game, double dir_x, double dir_y)
{
	game->player_dir_x = dir_x;
	game->player_dir_y = dir_y;
}

static void	set_plane_dir(t_game *game, double dir_x, double dir_y)
{
	game->camera_plane_dir_x = dir_x;
	game->camera_plane_dir_y = dir_y;
}

static void	set_dir(t_game *game, char tgt)
{
	if (tgt == 'N')
	{
		set_ply_dir(game, 0, 1);
		set_plane_dir(game, 0.66, 0);
	}
	else if (tgt == 'S')
	{
		set_ply_dir(game, 0, -1);
		set_plane_dir(game, -0.66, 0);
	}
	else if (tgt == 'W')
	{
		set_ply_dir(game, -1, 0);
		set_plane_dir(game, 0, 0.66);
	}
	else if (tgt == 'E')
	{
		set_ply_dir(game, 1, 0);
		set_plane_dir(game, 0, -0.66);
	}
}

void	init_player(t_game *game)
{
	size_t	i;
	size_t	j;
	char	tgt;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\n')
		{
			tgt = game->map[i][j];
			if (tgt == 'N' || tgt == 'W' || tgt == 'E' || tgt == 'S')
			{
				game->player_pos_x = j + 0.5;
				game->player_pos_y = i + 0.5;
				set_dir(game, tgt);
			}
			j++;
		}
		i++;
	}
}
