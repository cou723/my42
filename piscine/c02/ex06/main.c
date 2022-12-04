#include<stdio.h>
int	ft_str_is_printable(char *str);
int main()
{
	char *str = "asdfjkl;s\ndfjkla;";
	printf("%d\n",ft_str_is_printable(str));
}
