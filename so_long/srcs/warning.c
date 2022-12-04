/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:46:49 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <so_long.h>
#include <libft.h>
#include <unistd.h>

void	put_warning(void)
{
	ssize_t	write_len;
	size_t	retry_count;

	retry_count = 10;
	write_len = -1;
	while (write_len == -1 && retry_count > 0)
	{
		write_len = ft_putstr_fd("Warning\n", 2);
		retry_count--;
	}
}

void	put_warning_duplicate_player(size_t player_count)
{
	ssize_t	write_len;
	size_t	retry_count;

	put_warning();
	retry_count = 10;
	write_len = -1;
	while (write_len == -1 && retry_count > 0)
	{
		write_len = ft_putnbr_fd(player_count, 2);
		retry_count--;
	}
	retry_count = 10;
	write_len = -1;
	while (write_len == -1 && retry_count > 0)
	{
		write_len = ft_putstr_fd(DUPLICATE_PLAYER_MESSAGE, 2);
		retry_count--;
	}
}

void	check_warning_multiple_player(const char **map)
{
	size_t		player_count;
	const char	*line;

	player_count = 0;
	while (*map != NULL)
	{
		line = *map;
		while (*line != '\0')
		{
			if (*line == PLAYER)
				player_count++;
			line++;
		}
		map++;
	}
	if (player_count > 1)
		put_warning_duplicate_player(player_count);
}
