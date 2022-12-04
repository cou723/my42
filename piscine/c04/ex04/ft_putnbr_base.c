#include <unistd.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0

int	get_base(char *base)
{
	int	count;

	count = 0;
	base--;
	while (*++base != '\0')
		count++;
	return (count);
}

int	is_base_normal(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-')
			return (FALSE);
		while (j < get_base(base))
		{
			if (!(i == j) && base[i] == base[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (FALSE);
	return (TRUE);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		count;
	char	*i_ptr;
	int		minus;
	char	o_nums[33];

	if (!is_base_normal(base))
		return ;
	if (nbr == 0)
		write(1, &base[0], 1);
	i_ptr = &o_nums[sizeof(o_nums) - 1];
	count = 0;
	minus = 1;
	if (nbr < 0)
		minus = -1;
	while (nbr)
	{
		*--i_ptr = base[nbr % get_base(base) * minus];
		nbr /= get_base(base);
		count++;
	}
	if (minus == -1)
		write(1, "-", 1);
	write(1, i_ptr, count);
}
