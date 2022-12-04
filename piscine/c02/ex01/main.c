#include <stdio.h>
char *ft_strncpy(char *dest, char *src, unsigned int copy_size);
int	  main()
{
	char d1[10], s[] = "string";
	printf("s:%s\n", s);
	ft_strncpy(d1, s, 4);
	printf("d1:%s\n", d1);
	for (size_t i = 0; i < 10; i++)
	{
		printf("%ld,%x\n", i, d1[i]);
	}
}
