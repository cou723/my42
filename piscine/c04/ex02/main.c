#include <limits.h>
#include <stdio.h>
void ft_putnbr(int nb);

int main()
{
	int nb = 0;
	ft_putnbr(nb);
	printf("\n");
	for (int i = INT_MIN; i < INT_MAX; i += 100000)
	{
		ft_putnbr(i);
		printf("\n");
	}
}
