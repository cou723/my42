/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:03:02 by *******           #+#    #+#             */
/*   Updated: 2023/01/09 11:51:32 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdbool.h>
#include <stddef.h>

bool	has_key(t_strs envp, char *key)
{
	while (*envp != NULL)
	{
		if (ft_strlen(*envp) < ft_strlen(key))
		{
			envp++;
			continue ;
		}
		if ((ft_strncmp(*envp, key, ft_strlen(key)) == 0)
			&& ((*envp)[ft_strlen(key)] == '='
			|| (*envp)[ft_strlen(key)] == '+'))
			return (true);
		envp++;
	}
	return (false);
}

// must null check
char	*get_key(char *env_line)
{
	int		i;
	char	*key;

	i = 0;
	while (!(env_line[i] == '=' || env_line[i] == '+' || env_line[i] == '\0'))
		i++;
	key = ft_substr(env_line, 0, i);
	return (key);
}

// must null check
char	*get_value(char *env_line)
{
	while (!(*env_line == '=' || *env_line == '\0'))
		env_line++;
	return (ft_strdup(env_line + 1));
}

// must null check
char	*get_value_envp(t_strs envp, char *key)
{
	char	*envp_key;

	while (*envp != NULL)
	{
		envp_key = wrap_malloc(get_key(*envp));
		if (ft_strlen(key) == 0)
		{
			free(envp_key);
			return (NULL);
		}
		if (strequ(envp_key, key))
		{
			free(envp_key);
			return (get_value(*envp));
		}
		free(envp_key);
		envp++;
	}
	return (NULL);
}
