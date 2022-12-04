#include <stdio.h>
int ft_atoi(char *str);
int main()
{
	printf("%d\n", ft_atoi(" -2147483648"));
	printf("%d\n", ft_atoi(" -+-2147483647"));
	printf("%d\n", ft_atoi(" ---2147483648"));
	printf("%d\n", ft_atoi(" 0"));
	printf("%d\n", ft_atoi("\x09\x0a\x0b\x0c\x0d -2147483648-10000"));
}
