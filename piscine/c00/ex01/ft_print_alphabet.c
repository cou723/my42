#include<unistd.h>
void	ft_print_alphabet(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < 26)
	{
		c = 'a' + i;
		write(1, &c, 1);
		i++;
	}
}
