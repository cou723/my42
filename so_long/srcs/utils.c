/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:22:26 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <stddef.h>
#include <stdio.h>
#include <so_long.h>

char	*ft_strdup_null_allowable(const char *str)
{
	if (str == NULL)
		return (NULL);
	return (ft_strdup(str));
}

char	*ft_strjoin_null_allowable(const char *s1, const char *s2)
{
	if (s1 == NULL)
		return (ft_strdup_null_allowable(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	return (ft_strjoin(s1, s2));
}

void	free_map(const char **map)
{
	size_t	i;

	if (map != NULL)
	{
		i = 0;
		while (map[i] != NULL)
		{
			free((void *)map[i]);
			i++;
		}
	}
	free((void *)map);
}

size_t	get_map_height(const char **map)
{
	size_t	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	get_fd(const char *path)
{
	int	f;

	f = open(path, O_RDONLY);
	if (f == -1)
	{
		put_error();
		perror("so_long");
	}
	return (f);
}
