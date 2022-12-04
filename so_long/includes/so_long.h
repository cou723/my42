/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:01:14 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdbool.h>
# include <stddef.h>

# define USAGE "USAGE:\n    so_long [map_file.ber]\n\n"
# define DUPLICATE_PLAYER_MESSAGE " PLAYER START points were detected\
 on the map. \nOnly the first player start point detected is valid.\n\n"
# define INTERNAL_ERROR_MESSAGE "internal error occurred\n"
# define ERROR_MESSAGE "Error\n"
# define MAP_NOT_WALLED "The map must be walled in.\n\n"
# define NOT_RECTANGLE "The map must be rectangular\n\n"
# define NOT_EXIST_COLLECTION "Collective does not exist in the map\n\n"
# define NOT_EXIST_EXIT "Exit does not exist in the map\n\n"
# define NOT_EXIST_START_POSITION "Start position does not exist in\
 the map\n\n"
# define INVALID_CHARACTER "Invalid character detected in the map\n\n"
# define MAP_IS_EMPTY "The map is empty\n\n"
# define NOT_RECT_OR_EMPTY "The map is not rectangular or empty\n\n"
# define MAP_CONTAIN_BLANK_LINE "The map must not contain blank line\n\n"
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define IMAGE_WIDTH 32

typedef enum e_map_error
{
	NOT_WALL,
	NOT_RECT
}				t_map_error;

typedef struct s_must_list
{
	bool		exit;
	bool		start_pos;
	bool		collective;
}				t_must_list;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_player
{
	t_pos		pos;
	void		*img;
}				t_player;

typedef struct s_map
{
	char		**map;
	void		*wall_img;
	void		*collective_img;
	void		*exit_img;
	void		*void_img;
	size_t		collective_count;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
}				t_game;

void			put_error(void);
void			put_usage(void);
void			put_not_ber_file(const char *filename);
bool			put_map_not_walled_in(void);
bool			put_not_rectangle(void);
void			put_not_rectangle_or_empty(void);
void			put_map_item_error_message(t_must_list must_item);
bool			put_invalid_character(void);
void			put_error_message(const char *error_message);
bool			check_correct_args(int argc, char const *argv[]);
bool			check_correct_map(const char **map);
void			run_game(const char **map);
void			free_map(const char **map);
void			check_warning_multiple_player(const char **map);
char			*ft_strdup_null_allowable(const char *str);
char			*ft_strjoin_null_allowable(const char *s1, const char *s2);
size_t			get_map_height(const char **map);
bool			check_walled(const char **map);
int				get_fd(const char *path);
const char		**get_map_data(int fd);
//event.c
int				key_press(int key, void *param);
int				win_show(t_game *game);
int				win_close(t_game *game);
//init.c
bool			init_game(t_game *game, const char **map);
// free.c
void			free_game_map(void *mlx, t_map *map);
void			free_player(void *mlx, t_player *player);
//move.c
void			try_move_up(t_game *game);
void			try_move_down(t_game *game);
void			try_move_left(t_game *game);
void			try_move_right(t_game *game);
//display.c
void			display_map(t_game *game);
void			display_map_tile(t_game *game, char c, int x, int y);
void			display_sprite(t_game *game, int x, int y, void *img);
void			update_player(t_game *game);
void			put_count(size_t count);
#endif /* SO_LONG_H */
