/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:32:04 by my_pair           #+#    #+#             */
/*   Updated: 2022/11/22 22:32:49 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	count_size;

	count_size = count * size;
	if (count_size == 0)
		count_size = 1;
	if (count && size > SSIZE_MAX / count)
		count_size = SSIZE_MAX;
	res = malloc(count_size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
