#include <stdio.h>
char *ft_strcapitalize(char *str);
int	  main()
{
	char  str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char *result = ft_strcapitalize(str);
	printf("%s\n", result);
}
