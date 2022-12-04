/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:30:47 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t size)
{
	unsigned char	*uc_str1;
	unsigned char	*uc_str2;

	uc_str1 = (unsigned char *)str1;
	uc_str2 = (unsigned char *)str2;
	while (size != 0)
	{
		if (*uc_str1 != *uc_str2)
			return (*uc_str1 - *uc_str2);
		uc_str1++;
		uc_str2++;
		size--;
	}
	return (0);
}
