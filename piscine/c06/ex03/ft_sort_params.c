#include <unistd.h>
#define TRUE 1
#define FALSE 0
void	putstr_r(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
	write(1, "\n", 1);
}

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

void	output_sort_params(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (j_than_i_large_is(argv[j], argv[i]) && (i != j))
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
		putstr_r(argv[i++]);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	output_sort_params(argc, argv);
}
