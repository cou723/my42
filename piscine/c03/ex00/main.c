#include <stdio.h>
#include <string.h>
int ft_strcmp(char *s1, char *s2);

int main()
{
	char a1[] = "AB", b1[] = "AB";
	printf("ft_strcmp:%d\n", ft_strcmp(a1, b1));
	printf("strcmp:%d\n", strcmp(a1, b1));
	char a2[] = "ABC", b2[] = "AB";
	printf("ft_strcmp:%d\n", ft_strcmp(a2, b2));
	printf("strcmp:%d\n", strcmp(a2, b2));
	char a3[] = "AB", b3[] = "aB";
	printf("ft_strcmp:%d\n", ft_strcmp(a3, b3));
	printf("strcmp:%d\n", strcmp(a3, b3));
	char a4[] = "AB", b4[] = "AB";
	printf("ft_strcmp:%d\n", ft_strcmp(a4, b4));
	printf("strcmp:%d\n", strcmp(a4, b4));
	char a5[] = "AB", b5[] = "AB";
	printf("ft_strcmp:%d\n", ft_strcmp(a5, b5));
	printf("strcmp:%d\n", strcmp(a5, b5));
}
