/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:59:23 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*mapped_str;
	unsigned int	i_str;

	if (str == NULL || f == NULL)
		return (NULL);
	mapped_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (mapped_str == NULL)
		return (NULL);
	i_str = 0;
	while (str[i_str] != '\0')
	{
		mapped_str[i_str] = (*f)(i_str, str[i_str]);
		i_str++;
	}
	mapped_str[i_str] = '\0';
	return (mapped_str);
}
