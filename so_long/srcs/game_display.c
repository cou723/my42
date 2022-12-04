/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:46:32 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>
#include <so_long.h>

void	display_sprite(t_game *game, int x, int y, void *img)
{
	// return あまくない
	mlx_put_image_to_window(game->mlx, game->win, img, x * IMAGE_WIDTH, y
		* IMAGE_WIDTH);
}

void	display_map_tile(t_game *game, char c, int x, int y)
{
	if (c == '1')
		display_sprite(game, x, y, game->map->wall_img);
	else if (c == 'C')
		display_sprite(game, x, y, game->map->collective_img);
	else if (c == 'E')
		display_sprite(game, x, y, game->map->exit_img);
	else if (c == '0' || c == 'P')
		display_sprite(game, x, y, game->map->void_img);
}

void	display_map(t_game *game)
{
	int			x;
	int			y;
	const char	*line;

	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		line = game->map->map[y];
		while (line[x] != '\0')
		{
			display_map_tile(game, line[x], x, y);
			x++;
		}
		y++;
	}
}

void	update_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player->img,
		game->player->pos.x * IMAGE_WIDTH, game->player->pos.y
		* IMAGE_WIDTH);
}

void	put_count(size_t count)
{
	char	str[20];
	size_t	i;

	str[19] = '\0';
	i = 18;
	if (count == 0)
		str[i--] = '0';
	while (count > 0)
	{
		str[i] = count % 10 + '0';
		count /= 10;
		i--;
	}
	ft_putstr_fd(&str[i + 1], 0);
	ft_putchar_fd('\n', 0);
}
