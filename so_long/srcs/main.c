/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:24:13 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, const char *argv[])
{
	const char	**map;

	if (!check_correct_args(argc, argv))
		return (1);
	map = get_map_data(get_fd(argv[1]));
	if (map == NULL)
		return (1);
	if (!check_correct_map(map))
	{
		free_map(map);
		return (0);
	}
	run_game(map);
	free_map(map);
	return (0);
}
