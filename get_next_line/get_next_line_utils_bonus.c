/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:43:37 by marvin            #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	char_c;

	if (s == NULL)
		return (NULL);
	char_c = (char)c;
	while (*s != '\0')
	{
		if (*s == char_c)
			return ((char *)s);
		s++;
	}
	if (char_c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;

	if (dest_size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dest_size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *str, size_t start, size_t len)
{
	char	*rtn_str;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) <= start || len == 0)
		return (ft_strdup(""));
	rtn_str = (char *)malloc((len + 1) * sizeof(char));
	if (rtn_str == NULL)
		return (NULL);
	ft_strlcpy(rtn_str, str + start, len + 1);
	return (rtn_str);
}

char	*ft_strdup(const char *str)
{
	char	*p;

	if (str == NULL)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, str, ft_strlen(str) + 1);
	return (p);
}
