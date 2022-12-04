#include <stdio.h>
#include <unistd.h>

void ft_putnbr(int nb)
{
	int	  count;
	char *i_ptr;
	int	  minus;
	char  o_nums[13];

	i_ptr = &o_nums[sizeof(o_nums) - 1];
	count = 0;
	minus = 1;
	if (nb < 0)
		minus = -1;
	while (nb)
	{
		*--i_ptr = nb % 10 * minus;
		printf("nb％10:<%d>, ptr: <%p>\n", nb % 10, i_ptr);
		*i_ptr += '0';
		printf("*i_ptr: <%c>\n", *i_ptr);
		nb /= 10;
		printf("nb/10: <%d>\n", nb);
		printf("----------------\n");
		count++;
	}
	if (minus == -1)
		*--i_ptr = '-';
	write(1, i_ptr, count);
}

char *convert_10_to_16(unsigned long int num, char *str_prt)
{
	char  buf[17];
	char *result_str;
	int	  i;

	i = 0;
	result_str = &buf[sizeof(buf) - 1];
	while (i < 16)
	{
		if (num)
		{
			*--result_str = num % 16;
			if (10 > *result_str)
				*result_str += '0';
			else
				*result_str += ('a' - 10);
			num /= 16;
		}
		else
			*--result_str = '0';
		//printf("result_str:%c\n", *result_str);
		i++;
	}
	str_prt = result_str;
	return (str_prt);
}
