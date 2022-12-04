#include<stdio.h>
int	ft_sqrt_ex(int nb)
{
	unsigned long long	buf;
	unsigned long long	ull_nb;

	buf = 0;
	ull_nb = (unsigned long long)nb;
	while ((buf * buf) < ull_nb)
	{
		buf++;
		if ((buf * buf) >= ull_nb)
			return (buf);
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	unsigned long long int	x;
	unsigned long long int	sqrt;

	if (nb <= 1)
		return (0);
	if (nb % 2 != 0 || nb == 2 || nb == 3)
	{
		x = 3;
		sqrt = (unsigned long long int)ft_sqrt_ex(nb) + 2;
		while (x < sqrt)
		{
			if (nb % x == 0)
				return (0);
			x += 2;
		}
		return (1);
	}
	else
		return (0);
}
