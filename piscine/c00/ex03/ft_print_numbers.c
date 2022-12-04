#include<unistd.h>
void	ft_print_numbers(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = '0' + i;
		write(1, &c, 1);
		i++;
	}
}
