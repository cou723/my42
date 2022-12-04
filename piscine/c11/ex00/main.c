#include <stdio.h>
void ft_foreach(int *tab, int length, void (*f)(int));
void putnbr(int i)
{
	printf("%d\n", i);
}

int main()
{
	int arr[] = {1, 6, 4, 5, 78, 8, 345, 342, 678, 567, 23};
	ft_foreach((int*)arr, sizeof(arr) / sizeof(int), &putnbr);
}
