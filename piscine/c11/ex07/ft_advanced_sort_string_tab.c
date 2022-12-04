#include<stdio.h>
#define TRUE 1
#define FALSE 0

int	j_than_i_large_is(char *i, char *j)
{
	while (*i != '\0' || *j != '\0')
	{
		if (*i > *j)
			return (1);
		else if (*i < *j)
			return (-1);
		i++;
		j++;
	}
	return (0);
}

void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[j] != NULL)
		{
			if (cmp(tab[j], tab[i]) == 1 && (i != j))
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
