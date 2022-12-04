#include <unistd.h>
void	output(int count, char *i_ptr)
{
	write(1, i_ptr, count);
	write(1, "\n", 1);
}

void	ll_putnbr_r(long long nb)
{
	int		count;
	char	*i_ptr;
	int		minus;
	char	o_nums[1024];

	i_ptr = &o_nums[sizeof(o_nums) - 1];
	count = 0;
	minus = 1;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
		minus = -1;
	while (nb)
	{
		*--i_ptr = nb % 10 * minus;
		*i_ptr += '0';
		nb /= 10;
		count++;
	}
	if (minus == -1)
	{
		*--i_ptr = '-';
		count++;
	}
	output(count, i_ptr);
}
