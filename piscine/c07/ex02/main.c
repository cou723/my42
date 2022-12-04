#include <stdio.h>
#include <stdlib.h>
int ft_ultimate_range(int **range, int min, int max);
int main(int argc,char *argv[])
{
	(void)argc;
	int  *range;
	int	  n = ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2]));
	printf("%d\n", n);
	if (range == NULL)
	{
		printf("return NULL\n");
	}
	for (int i = 0; i < n; i++)
	{
		printf("i:%d,%d\n", i, (range)[i]);
	}
	free(range);
}
