/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_pair <my_pair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:40:43 by my_pair           #+#    #+#             */
/*   Updated: 2022/12/04 14:40:44 by my_pair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_config_by_null(t_game *game)
{
	game->config.n_path = NULL;
	game->config.s_path = NULL;
	game->config.w_path = NULL;
	game->config.e_path = NULL;
	game->config.floor_color[0] = -1;
	game->config.ceiling_color[0] = -1;
}

static void	init_img(t_game *game, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	init_config(int fd, t_game *game)
{
	int	tmp;

	init_config_by_null(game);
	read_config(fd, game);
	tmp = wopen(game->config.n_path, O_RDONLY);
	close(tmp);
	tmp = wopen(game->config.s_path, O_RDONLY);
	close(tmp);
	tmp = wopen(game->config.w_path, O_RDONLY);
	close(tmp);
	tmp = wopen(game->config.e_path, O_RDONLY);
	close(tmp);
	init_img(game, &game->n_img, game->config.n_path);
	init_img(game, &game->s_img, game->config.s_path);
	init_img(game, &game->w_img, game->config.w_path);
	init_img(game, &game->e_img, game->config.e_path);
}
