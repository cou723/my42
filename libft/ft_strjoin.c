/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:22:23 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	size_t	malloc_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	malloc_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s1s2 = malloc(sizeof(char) * malloc_len);
	if (s1s2 == NULL)
		return (NULL);
	ft_strlcpy(s1s2, s1, malloc_len);
	ft_strlcat(s1s2, s2, malloc_len);
	return (s1s2);
}
