/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2022/01/12 18:05:43 by *******           #+#    #+#             */
/*   Updated: 2022/02/01 18:50:07 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*p;

	if (str == NULL)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, str, ft_strlen(str) + 1);
	return (p);
}
