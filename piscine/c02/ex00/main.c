#include <stdio.h>
#include <string.h>
char *ft_strcpy(char *dest, char *src);
int	  main()
{
	char d1[7], s[] = "string";
	printf("%s\n", ft_strcpy(d1, s));
	printf("%s\n", d1);
}
