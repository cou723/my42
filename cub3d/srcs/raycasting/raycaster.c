/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:10:26 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <mlx.h>

void	set_wall(t_game *game, t_ray *ray, t_texture *texture)
{
	if (ray->prep_side == X_SIDE)
	{
		if (ray->dir_x > 0)
			texture->wall = &game->e_img;
		else
			texture->wall = &game->w_img;
	}
	else
	{
		if (ray->dir_y > 0)
			texture->wall = &game->n_img;
		else
			texture->wall = &game->s_img;
	}
}

void	dda(t_game *game, t_ray *ray)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->prep_side = X_SIDE;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->prep_side = Y_SIDE;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

void	calc_wall_height(t_ray *ray)
{
	if (ray->prep_side == X_SIDE)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	if (ray->perp_wall_dist)
		ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	else
		ray->line_height = INF;
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT;
}

void	calc_coordinates_of_wall(t_game *game, t_ray *ray, t_texture *texture)
{
	if (ray->prep_side == X_SIDE)
		texture->wall_x = game->player_pos_y - ray->perp_wall_dist * ray->dir_y;
	else
		texture->wall_x = game->player_pos_x + ray->perp_wall_dist * ray->dir_x;
	texture->wall_x -= floor(texture->wall_x);
	texture->x = (int)(texture->wall_x * (double)(texture->wall->width));
	if ((ray->prep_side == X_SIDE && ray->dir_x < 0)
		|| (ray->prep_side == Y_SIDE && ray->dir_y < 0))
		texture->x = texture->wall->width - texture->x - 1;
	texture->step = 1.0 * texture->wall->height / ray->line_height;
	texture->texture_pos = (ray->draw_start - SCREEN_HEIGHT / 2.0
			+ ray->line_height / 2.0) * texture->step;
}

int	display_screen(t_game *game)
{
	t_ray		ray;
	t_texture	to_display;
	int			x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray(game, &ray, x);
		dda(game, &ray);
		set_wall(game, &ray, &to_display);
		calc_wall_height(&ray);
		calc_coordinates_of_wall(game, &ray, &to_display);
		draw_line(game, &ray, &to_display, x);
		++x;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	return (0);
}
