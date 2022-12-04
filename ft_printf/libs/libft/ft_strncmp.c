/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:32:33 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	char	*u_s1;
	char	*u_s2;

	u_s1 = (unsigned char)*s1;
	u_s2 = (unsigned char)*s2;
	while (len != 0 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (u_s1 - u_s2);
		s1++;
		s2++;
		len--;
	}
	if (len == 0)
		return (0);
	return (u_s1 - u_s2);
}
