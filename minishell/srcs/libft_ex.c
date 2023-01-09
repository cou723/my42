/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:30:59 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "minishell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// must null check
char	*ft_strdup_null_safe(const char *str)
{
	if (str == NULL)
		return (NULL);
	return (ft_strdup(str));
}

// must null check
char	*ft_strjoin_null_allow(const char *s1, const char *s2)
{
	if (s1 == NULL)
		return (ft_strdup_null_safe(s2));
	if (s2 == NULL)
		return (ft_strdup_null_safe(s1));
	return (ft_strjoin(s1, s2));
}
