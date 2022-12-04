/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:31:55 by marvin            #+#    #+#             */
/*   Updated: 2022/12/04 21:48:31 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*add_file_text(int fd, char *buf);
static char	*get_after_ln(char *str);
static char	*get_before_ln(char *str);
static char	*buf_join(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char	*after_ln[OPEN_MAX + 1UL];
	char		*file_text;
	char		*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(after_ln[fd], '\n') == NULL)
		text = add_file_text(fd, after_ln[fd]);
	else
		text = ft_strdup(after_ln[fd]);
	free(after_ln[fd]);
	after_ln[fd] = NULL;
	if (text == NULL)
		return (NULL);
	after_ln[fd] = get_after_ln(text);
	file_text = get_before_ln(text);
	free(text);
	return (file_text);
}

static char	*add_file_text(int fd, char *text)
{
	char	*read_buf;
	char	*tmp;
	ssize_t	len;

	read_buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (read_buf == NULL)
		return (NULL);
	len = read(fd, read_buf, BUFFER_SIZE);
	text = ft_strdup(text);
	while (len > 0)
	{
		read_buf[len] = '\0';
		tmp = buf_join(text, read_buf);
		free(text);
		text = tmp;
		if (ft_strchr(text, '\n') || text == NULL)
			break ;
		len = read(fd, read_buf, BUFFER_SIZE);
	}
	free(read_buf);
	if (len == -1)
		return (NULL);
	return (text);
}

static char	*get_before_ln(char *str)
{
	char	*newline_code_pos;
	size_t	before_ln_len;
	char	*before_ln;

	if (str == NULL || ft_strlen(str) == 0)
		return (NULL);
	newline_code_pos = ft_strchr(str, '\n');
	if (newline_code_pos == NULL)
		return (ft_strdup(str));
	before_ln_len = ft_strlen(str) - ft_strlen(newline_code_pos) + 1;
	if (before_ln_len == 0)
		return (NULL);
	before_ln = ft_substr(str, 0, before_ln_len);
	return (before_ln);
}

// "str" must contain a null character.
// if "str" doesnt contains it, return NULL.
static char	*get_after_ln(char *str)
{
	char	*newline_code_pos;
	size_t	after_ln_len;
	char	*after_ln;

	if (str == NULL)
		return (NULL);
	newline_code_pos = ft_strchr(str, '\n');
	if (newline_code_pos == NULL)
		return (NULL);
	after_ln_len = ft_strlen(newline_code_pos + 1);
	if (after_ln_len == 0)
		return (NULL);
	after_ln = ft_substr(str, ft_strlen(str) - after_ln_len, after_ln_len);
	return (after_ln);
}

// This strjoin allows s1 to be null.
static char	*buf_join(char *s1, char *s2)
{
	char	*joined_str;
	size_t	malloc_len;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	malloc_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_str = malloc(sizeof(char) * malloc_len);
	if (joined_str == NULL)
		return (NULL);
	ft_strlcpy(joined_str, s1, malloc_len);
	ft_strlcpy(joined_str + ft_strlen(s1), s2, malloc_len - ft_strlen(s1));
	return (joined_str);
}
