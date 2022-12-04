#include<unistd.h>
void	ft_print_comb2(void)
{
	int		index1;
	int		index2;
	char	c1[3];
	char	c2[3];

	index1 = 0;
	while (index1 < 100)
	{
		c1[0] = '0' + index1 / 10;
		c1[1] = '0' + index1 % 10;
		index2 = index1 + 1;
		while (index2 < 100)
		{
			c2[0] = '0' + index2 / 10;
			c2[1] = '0' + index2 % 10;
			write(1, &c1, 2);
			write(1, " ", 1);
			write(1, &c2, 2);
			if (!(index1 == 98 && index2 == 99))
				write(1, ", ", 2);
			index2++;
		}
		index1++;
	}
}
