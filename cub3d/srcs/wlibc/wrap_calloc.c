/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_pair <my_pair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:41:15 by my_pair           #+#    #+#             */
/*   Updated: 2022/12/04 14:41:16 by my_pair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*wcalloc(size_t count, size_t size)
{
	void	*buf;

	buf = ft_calloc(count, size);
	if (!buf)
	{
		xput_error("malloc error");
		exit(-1);
	}
	return (buf);
}
