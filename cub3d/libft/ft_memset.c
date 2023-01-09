/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_pair   <my_pair@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:38:33 by my_pair           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:34 by my_pair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	c;
	unsigned char	*str;

	i = 0;
	c = ch;
	str = (unsigned char *)buf;
	while (i < n)
	{
		*str++ = c;
		i ++;
	}
	return (buf);
}
