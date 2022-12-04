#include <stdio.h>
#include <unistd.h>
int pow(int base, int count)
{
	int	num;

	if (count == 0)
		return (1);
	num = base;
	while (count > 1)
	{
		num = num * base;
		count--;
	}
	return (num);
}

int is_output(int nb, int num[])
{
	int	return_num;
	int	i;

	i = 0;
	return_num = (num[0] < num[1]);
	//printf("return_num:%d\n", return_num);
	i++;
	while (i < nb - 1)
	{
		return_num = return_num & (num[i] < num[i + 1]);
		//printf("return_num:%d,i:%d,num[i]:%d,num[i+1]:%d\n", return_num, i, num[i], num[i +1]);
		i++;
	}
	//printf("return_num:%d\n", return_num);
	return (return_num);
}

int get_max(int nb)
{
	if (nb == 1)
		return (9);
	else if (nb == 2)
		return (89);
	else if (nb == 3)
		return (789);
	else if (nb == 4)
		return (6789);
	else if (nb == 5)
		return (56789);
	else if (nb == 6)
		return (456789);
	else if (nb == 7)
		return (3456789);
	else if (nb == 8)
		return (23456789);
	else if (nb == 9)
		return (123456789);
	return (0);
}

void put(int nb, int *num, int n)
{
	int		i;
	char	c[11];

	i = 0;
	while (i < nb)
	{
		c[i] = num[i] + '0';
		i++;
	}
	write(1, &c, nb);
	if (n != get_max(nb))
		write(1, ", ", 2);
}

void ft_print_combn(int nb)
{
	int	n;
	int	i;
	int	num[9];

	//printf("----------\n");
	n = 0;
	//printf("nb:%d\n", nb);
	while (n <= get_max(nb))
	{
		//printf("n:%d\n", n);
		i = 0;
		while (i < nb)
		{
			num[nb - 1 - i] = (n / pow(10, i)) % 10;
			//printf("i:%d\n", i);
			i++;
		}
		//printf("<%d,%d,%d,%d>\n", num[0], num[1], num[2], num[3]);
		if (is_output(nb, num))
			put(nb, num, n);
		n++;
		//printf("----------\n");
	}
}

int main()
{
	ft_print_combn(3);
}
