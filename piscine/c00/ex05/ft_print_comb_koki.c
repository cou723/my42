#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_comb(void)
{
	int	 n;
	int	 num[3];
	char c[6];

	n = 0;
	while (n < 1000)
	{
		num[0] = (n / 100) % 10;
		num[1] = (n / 10) % 10;
		num[2] = (n / 1) % 10;
		//printf("<%d,%d,%d>", num[0], num[1], num[2]);
		if (num[0] < num[1] && num[1] < num[2] && num[1] < num[2])
		{
			c[0] = num[0] + '0';
			c[1] = num[1] + '0';
			c[2] = num[2] + '0';
			write(1, &c, 3);
			if (n != 789)
			{
				c[3] = ',';
				c[4] = ' ';
				write(1, &c[3], 2);
			}
		}
		n++;
	}
}

int main()
{
	ft_print_comb();
}
