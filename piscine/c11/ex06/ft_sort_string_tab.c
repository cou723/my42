#include<stdio.h>
#define TRUE 1
#define FALSE 0

int	j_than_i_large_is(char *i, char *j)
{
	while (*i != '\0' || *j != '\0')
	{
		if (*i > *j)
			return (TRUE);
		else if (*i < *j)
			return (FALSE);
		i++;
		j++;
	}
	return (FALSE);
}

void ft_sort_string_tab(char **tab)
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
			if (j_than_i_large_is(tab[j], tab[i]) && (i != j))
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
