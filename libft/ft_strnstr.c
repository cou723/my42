/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:06:43 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*rtn_ptr;
	size_t	i;

	rtn_ptr = NULL;
	i = 0;
	if (len < ft_strlen(little))
		return (NULL);
	len -= ft_strlen(little);
	while (i <= len && big[i] != '\0')
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0)
		{
			rtn_ptr = (char *)(big + i);
			break ;
		}
		i++;
	}
	return (rtn_ptr);
}
