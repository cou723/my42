#include<unistd.h>
void	ft_print_alphabet(void)
{
	int	i;
	char	c;

	i = 0;
	while (i < 28)
	{
		c = 'a' + 2;
		write(1,&c,1);
	}
}

int	main(void){
	ft_print_alphabet();
}
