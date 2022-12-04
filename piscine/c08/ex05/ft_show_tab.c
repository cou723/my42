#include "ft_stock_str.h"
#include <unistd.h>
void	putnbr(int nb)
{
	int		count;
	char	*i_ptr;
	int		minus;
	char	o_nums[13];

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
	write(1, i_ptr, count);
}

void	putstr_r(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		putstr_r(par->str);
		putnbr(par->size);
		write(1, "\n", 1);
		putstr_r(par->copy);
		par++;
	}
}
