int ft_strncmp(char *s1, char *s2, unsigned int n);
#include <stdio.h>
#include <string.h>

int main()
{
	char a1[] = "AB", b1[] = "AB";
	printf("ft_strncmp:%d\n", ft_strncmp(a1, b1, 5));
	printf("strncmp:%d\n", strncmp(a1, b1, 5));
	char a2[] = "ABC", b2[] = "AB";
	printf("ft_strncmp:%d\n", ft_strncmp(a2, b2, 5));
	printf("strncmp:%d\n", strncmp(a2, b2, 5));
	char a3[] = "AB", b3[] = "aB";
	printf("ft_strncmp:%d\n", ft_strncmp(a3, b3, 5));
	printf("strncmp:%d\n", strncmp(a3, b3, 5));
	char a4[] = "ABC", b4[] = "AB";
	printf("ft_strncmp:%d\n", ft_strncmp(a4, b4, 2));
	printf("strncmp:%d\n", strncmp(a4, b4, 2));
	char a5[] = "AB", b5[] = "AB";
	printf("ft_strncmp:%d\n", ft_strncmp(a5, b5, 5));
	printf("strncmp:%d\n", strncmp(a5, b5, 5));
}
