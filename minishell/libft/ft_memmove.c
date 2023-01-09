/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:03:15 by *******           #+#    #+#             */
/*   Updated: 2022/01/31 13:25:34 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	void	*rtn_ptr;

	rtn_ptr = (void *)dest;
	if (len == 0 || dest == src)
		return (dest);
	if (src < dest)
	{
		while (len--)
			((char *)dest)[len] = ((char *)src)[len];
	}
	else
		ft_memcpy(dest, src, len);
	return (rtn_ptr);
}
