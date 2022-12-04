#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0 - 1;
	while (str[++count] != '\0')
		;
	return (count);
}

char	*ft_strdup(char *s)
{
	char	*rtn_str;
	int		s_size;
	int		i;

	s_size = 0;
	while (s[s_size] != '\0')
		s_size++;
	rtn_str = (char *)malloc(sizeof(char) * s_size);
	if (rtn_str == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		rtn_str[i] = s[i];
		i++;
	}
	return (rtn_str);
}


struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stru_p;
	int			i;

	if (av == NULL)
		return (NULL);
	stru_p = (t_stock_str *)malloc(sizeof(t_stock_str) * ac + 1);
	if (stru_p == NULL)
		return (NULL);
	while (av[i] && i < ac)
	{
		if (av[i] == NULL)
			return (NULL);
		stru_p[i].size = ft_strlen(av[i]);
		stru_p[i].str = av[i];
		stru_p[i].copy = ft_strdup(av[i]);
		i++;
	}
	stru_p[i].str = 0;
	return (stru_p);
}
