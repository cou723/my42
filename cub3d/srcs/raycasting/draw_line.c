/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:11:02 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static unsigned int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

static void	set_pixel_color(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_game *game, t_ray *ray, t_texture *texture, int x)
{
	unsigned int	color;
	int				y;

	y = 0;
	while (y < ray->draw_start && y < SCREEN_HEIGHT)
		set_pixel_color(&game->screen, x, y++,
			rgb_to_code_code(game->config.ceiling_color));
	while (y < ray->draw_end && y < SCREEN_HEIGHT)
	{
		texture->y = fmod(texture->texture_pos, texture->wall->height - 1);
		texture->texture_pos += texture->step;
		color = get_pixel_color(texture->wall, texture->x, texture->y);
		set_pixel_color(&game->screen, x, y++, color);
	}
	while (y < SCREEN_HEIGHT)
		set_pixel_color(&game->screen, x, y++,
			rgb_to_code_code(game->config.floor_color));
}
