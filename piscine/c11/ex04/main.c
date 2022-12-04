#include <stdio.h>
int ft_is_sort(int *tab, int length, int (*f)(int, int));
int fir_than_sec(int n1, int n2)
{
	printf("1:%d,2:%d\n",n1,n2);
	return n1 - n2;
}
int main()
{
	int tab[] = {1, 2, 3, 4, 5, 8, 7};
	printf("ans:%d\n", ft_is_sort(tab, 7, &fir_than_sec));
}
