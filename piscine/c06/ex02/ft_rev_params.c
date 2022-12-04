#include <unistd.h>
void	putstr_r(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	argc--;
	while (argc > 0)
		putstr_r(argv[argc--]);
}
