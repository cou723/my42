/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:32:45 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <so_long.h>
#include <stdio.h>

bool	check_correct_args(int argc, char const *argv[])
{
	if (argc != 2)
	{
		put_error();
		put_usage();
		return (false);
	}
	if (!(ft_strlen(argv[1]) >= 5 && ft_strncmp(&(argv[1][ft_strlen(argv[1])
					- 4]), ".ber", 4) == 0))
	{
		put_not_ber_file(argv[1]);
		return (false);
	}
	return (true);
}
