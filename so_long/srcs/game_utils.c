/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:47:22 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>
#include <stdlib.h>

void	free_game_map(void *mlx, t_map *map)
{
	if (map->collective_img != NULL)
		mlx_destroy_image(mlx, map->collective_img);
	if (map->exit_img != NULL)
		mlx_destroy_image(mlx, map->exit_img);
	if (map->wall_img != NULL)
		mlx_destroy_image(mlx, map->wall_img);
	if (map->void_img != NULL)
		mlx_destroy_image(mlx, map->void_img);
	free(map);
}

void	free_player(void *mlx, t_player *player)
{
	mlx_destroy_image(mlx, player->img);
	free(player);
}
