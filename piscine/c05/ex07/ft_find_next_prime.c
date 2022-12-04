int	ft_sqrt_ex(int nb)
{
	unsigned long long	buf;
	unsigned long long	ull_nb;

	buf = 0;
	ull_nb = (unsigned long long)nb;
	while ((buf * buf) < ull_nb)
		buf++;
	return (buf);
}

int	ft_is_prime(int nb)
{
	int	x;
	int	sqrt;

	if (nb == 0 || nb == 1)
		return (0);
	if (nb % 2 != 0 || nb == 2 || nb == 3)
	{
		x = 3;
		sqrt = ft_sqrt_ex(nb) + 1;
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

int	ft_find_next_prime(int nb)
{
	int	next_prime;

	if (nb < 0)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	next_prime = nb;
	while (1)
	{
		if (ft_is_prime(next_prime))
			return (next_prime);
		next_prime++;
	}
}
