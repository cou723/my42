#include <stdio.h>
#include <stdlib.h>
int *ft_range(int min, int max);
int	 main()
{
	int	 min = -1, max = 100;
	int *n_a = ft_range(min, max);
	if ((n_a) != NULL)
	{
		for (size_t i = 0; i < (unsigned long long)max - min; i++)
			printf("%ld:%d\n", i, n_a[i]);
	}
	free(n_a);
}
