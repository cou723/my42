/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_pair <my_pair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:41:18 by my_pair           #+#    #+#             */
/*   Updated: 2022/12/04 14:41:19 by my_pair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wopen(char *path, int flags)
{
	int	fd;

	fd = open(path, flags);
	if (fd == -1)
	{
		xput_error("open error");
		exit(-1);
	}
	return (fd);
}
