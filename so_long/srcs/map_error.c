/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:07:06 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdbool.h>
#include <stddef.h>

bool	put_map_not_walled_in(void)
{
	put_error();
	put_error_message(MAP_NOT_WALLED);
	return (false);
}

bool	put_not_rectangle(void)
{
	put_error();
	put_error_message(NOT_RECTANGLE);
	return (false);
}

void	put_map_item_error_message(t_must_list must_item)
{
	put_error();
	if (!must_item.collective)
		put_error_message(NOT_EXIST_COLLECTION);
	if (!must_item.exit)
		put_error_message(NOT_EXIST_EXIT);
	if (!must_item.start_pos)
		put_error_message(NOT_EXIST_START_POSITION);
}

void	put_not_rectangle_or_empty(void)
{
	put_error();
	put_error_message(NOT_RECT_OR_EMPTY);
}

bool	put_invalid_character(void)
{
	put_error();
	put_error_message(INVALID_CHARACTER);
	return (false);
}
