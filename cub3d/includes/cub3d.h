/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:20:45 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line_bonus.h"
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <sysexits.h>
# include <unistd.h>

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define INF 2147483647

# define KC_W 119
# define KC_A 97
# define KC_S 115
# define KC_D 100
# define KC_LEFT 65361
# define KC_RIGHT 65363
# define KC_ESC 65307

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define CLIENT_MESSAGE 33
# define KEY_PRESS_MASK 1L
# define KEY_RELEASE_MASK 2L
# define STRUCTURE_NOTIFY_MASK 131072
# define INF 2147483647

# define PLAYER_MOVE_SPEED 0.1
# define PLAYER_ROTATE_SPEED 0.01

typedef enum e_side
{
	X_SIDE,
	Y_SIDE
}					t_side;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef enum e_relative_dir
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
}					t_relative_dir;

typedef struct s_config
{
	char			*n_path;
	char			*s_path;
	int				s_img_w;
	int				s_img_h;
	char			*w_path;
	char			*e_path;
	int				floor_color[3];
	int				ceiling_color[3];
}					t_config;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	double			player_pos_x;
	double			player_pos_y;
	double			player_dir_x;
	double			player_dir_y;
	double			camera_plane_dir_x;
	double			camera_plane_dir_y;
	t_img			n_img;
	t_img			s_img;
	t_img			w_img;
	t_img			e_img;
	t_relative_dir	move_relative_dir;
	t_relative_dir	rotate_relative_dir;
	t_img			screen;
	t_config		config;
}					t_game;

typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	t_side			prep_side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_texture
{
	t_img			*wall;
	double			wall_x;
	double			step;
	int				x;
	int				y;
	double			texture_pos;
}					t_texture;

// main.c
void				xput_error(char *str);
// init.c
void				init_game(t_game *game, char *map_file_name);
void				init_config(int fd, t_game *game);
void				init_map(int fd, t_game *game);
void				init_player(t_game *game);
// cubfile.c
void				read_config(int fd, t_game *game);
void				read_map(int fd, t_game *game);
void				check_map_error(t_game *game);
// wlibc.c
int					wopen(char *path, int flags);
void				*wcalloc(size_t count, size_t size);
// raycast.c
int					display_screen(t_game *game);
void				init_ray(t_game *game, t_ray *ray, int x);
void				draw_line(t_game *game, t_ray *ray, t_texture *texture,
						int x);
// key_hooks.c
int					key_press_hook(int key_code, t_game *game);
int					key_release_hook(int key_code, t_game *game);
int					destroy_and_exit(void *arg);
// utils.c
int					rgb_to_code_code(int color[3]);
// update_player.c
void				update_player(t_game *game);
#endif
