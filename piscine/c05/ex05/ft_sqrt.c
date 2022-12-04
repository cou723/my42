#include<stdio.h>
int	ft_sqrt(int nb)
{
	unsigned long long	buf;

	if (nb < 0)
		return (0);
	buf = 0;
	while (buf * buf < (unsigned long long)nb)
	{
		buf++;
		if (buf * buf == (unsigned long long)nb)
			return (buf);
		if (buf * buf > (unsigned long long)nb)
			return (0);
	}
	return (0);
}
