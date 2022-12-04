#include <stdio.h>
unsigned int	get_str_size(char *array)
{
	unsigned int	i;

	i = -1;
	while (array[++i] != '\0')
		;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (get_str_size(src));
}
