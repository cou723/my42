#include<unistd.h>
void	putstr_r(char *str)
{
	str--;
	while (*++str != '\0')
		write(1, str, 1);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	putstr_r(argv[0]);
}
