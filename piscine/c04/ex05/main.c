#include <stdio.h>
int ft_atoi_base(char *str, char *base);
int main()
{
	printf("num:%d\n", ft_atoi_base("  --++---100fd#$54", "0123456789"));
	printf("num:%d\n", ft_atoi_base("  --++--2147483647-100", "0123456789"));
	printf("num:%d\n", ft_atoi_base("\x09\x0a\x0b\x0c\x0d  --++---1001010110", "01"));
}
