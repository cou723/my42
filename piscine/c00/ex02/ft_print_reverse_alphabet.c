#include<unistd.h>
void	ft_print_reverse_alphabet(void)
{
	int		i;
	char	c;

	i = 25 + 'a';
	while (i >= 'a')
	{
		c = i;
		write(1, &c, 1);
		i--;
	}
}
