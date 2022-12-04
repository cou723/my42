#include<unistd.h>
void	ft_print_comb(void)
{
	int		indexes[3];
	char	chars[4];

	indexes[0] = 0;
	while (indexes[0] < 10)
	{
		chars[0] = '0' + indexes[0];
		indexes[1] = indexes[0] + 1;
		while (indexes[1] < 10)
		{
			chars[1] = '0' + indexes[1];
			indexes[2] = indexes[1] + 1;
			while (indexes[2] < 10)
			{
				chars[2] = '0' + indexes[2];
				write(1, chars, 3);
				if (!(indexes[0] == 7 && indexes[1] == 8 && indexes[2] == 9))
					write(1, ", ", 2);
				indexes[2]++;
			}
			indexes[1]++;
		}
		indexes[0]++;
	}
}
