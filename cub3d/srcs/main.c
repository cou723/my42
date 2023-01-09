/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:08:44 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <mlx.h>

static int	game_loop(t_game *game)
{
	update_player(game);
	display_screen(game);
	return (0);
}

void	xput_error(char *str)
{
	ft_putstr_fd("error: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	check_arg(int argc, char **argv)
{
	char	*file_extension;
	char	*last_slash_pt;

	if (argc != 2)
		xput_error("invalid argument");
	last_slash_pt = ft_strrchr(argv[1], '/');
	if (ft_strncmp(argv[1], ".cub", 5) == 0 || (last_slash_pt
			&& last_slash_pt[1] == '.'))
		xput_error("invalid file name");
	file_extension = ft_strrchr(argv[1], '.');
	if (!file_extension || ft_strncmp(file_extension, ".cub", 5))
		xput_error("invalid file name");
}

static void	start_game(t_game *game)
{
	mlx_hook(game->win, KEY_PRESS, KEY_PRESS_MASK, key_press_hook, game);
	mlx_hook(game->win, KEY_RELEASE, KEY_RELEASE_MASK, key_release_hook, game);
	mlx_hook(game->win, CLIENT_MESSAGE, STRUCTURE_NOTIFY_MASK, destroy_and_exit,
		game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	check_arg(argc, argv);
	init_game(&game, argv[1]);
	start_game(&game);
}
