#include <stdio.h>
int ft_any(char **tab, int (*f)(char *));
int zero_or_one(char *str)
{
	return (str[0] > 10);
}
int main()
{
	char *strs[5] = {"minecraft", "tetris", "apex", "cubase"};
	for (int i = 0; i < 4; i++)
		printf("%s\n", strs[i]);
	strs[4] = 0;
	printf("ans:%d\n", ft_any((char **)strs, &zero_or_one));
}
