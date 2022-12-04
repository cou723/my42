//出力関係の関数
#include <unistd.h>

//outputs string function
void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

//output "Error" function
void	put_error()
{
	putstr("Error\n");
}

// Output a 4*4 two-dimensional array
void	put_answer(int *array, int map_length)
{
	int		i;
	int		j;
	char	output_string[1024];

	i = 0;
	j = 0;
	while (i < map_length)
	{
		while (j < map_length)
		{
			output_string[i] = array[i] + '0';
			j++;
		}
		output_string[i] = '\0';
		putstr(output_string);
		i++;
	}
}
