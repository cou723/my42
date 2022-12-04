#include <stdlib.h>

char	*my_strndup(char *s, int size)
{
	char	*rtn_str;
	int		s_size;
	int		i;

	s_size = 0;
	while (s[s_size] != '\0')
		s_size++;
	if (s_size > size)
		s_size = size;
	rtn_str = (char *)malloc(sizeof(char) * s_size + 1);
	if (rtn_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < s_size)
	{
		rtn_str[i] = s[i];
		i++;
	}
	rtn_str[i] = '\0';
	return (rtn_str);
}

int	is_c(char c, char *c_s)
{
	int	ans;

	ans = 0;
	c_s--;
	while (*(++c_s) != '\0')
		ans = ans || (int)(*c_s == c);
	return (ans);
}

int	count_word(char *str, char *c_s)
{
	int	ct;
	int	i;

	ct = 0;
	i = -1;
	while (str[++i] != '\0')
		if (i != 0)
			if (is_c(str[i], c_s)
				&& (!is_c(str[i - 1], c_s)))
				ct++;
	if (i == 1)
		return (is_c(str[i - 1], c_s));
	if (is_c(str[i - 1], c_s))
		return (ct);
	else
		return (ct + 1);
}

int	is_all_c_s(char *str, char *c_s)
{
	int	i;

	i = 1;
	while (*str != '\0')
	{
		i = i & (is_c(*str, c_s));
		str++;
	}
	return (i);
}

char	**ft_split(char *str, char *c_s)
{
	char	**rtn_strs;
	int		i;
	int		ct;
	int		w_ct;

	i = -1;
	w_ct = 0;
	ct = count_word(str, c_s);
	rtn_strs = (char **)malloc(sizeof(char *) * (ct + 1));
	while (is_c(*str, c_s))
		str++;
	while (1)
	{
		if ((is_c(*str, c_s) && !(is_c(str[-1], c_s))) || (*str == '\0'))
		{
			rtn_strs[++i] = my_strndup(&str[-cts[1]], cts[1]);
			cts[1] = 0;
		}
		cts[1] += (!is_c(*str, c_s));
		if (*str)
			break;
		str++;
	}
	rtn_strs[ct] = NULL;
	return (rtn_strs);
}
