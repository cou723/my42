#include <unistd.h>
#include "ll_putnbr.h"

void	put_add(int a, int b){
	ll_putnbr_r((long long)a + b);
}

void	put_sub(int a, int b)
{
	ll_putnbr_r((long long)a - b);
}

void	put_multi(int a, int b)
{
	ll_putnbr_r((long long)a * b);
}

void	put_division(int a, int b)
{
	if (b == 0)
		write(1, "Stop : division by zero\n", 24);
	else
		ll_putnbr_r((long long)a / b);
}

void	put_modulo(int a, int b)
{
	if (b == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		ll_putnbr_r((long long)a % b);
}
