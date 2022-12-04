#include <stdio.h>
int *ft_map(int *tab, int length, int (*f)(int));
int putnbr(int i)
{
	return (i);
}
int main()
{
	int arr[] = {1, 6, 4, 5, 78, 8, 345, 342, 678, 567, 23};
	int *x = ft_map((int *)arr, sizeof(arr) / sizeof(int), &putnbr);

	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d\n",x[i]);
	}
}
