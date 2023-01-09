/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_pair   <my_pair@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:30:25 by my_pair           #+#    #+#             */
/*   Updated: 2022/04/10 11:50:34 by my_pair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t;

	t = (char *)s;
	i = ft_strlen(t);
	while (i >= 0)
	{
		if (t[i] == (char)c)
			return (&t[i]);
		i --;
	}
	return (NULL);
}
