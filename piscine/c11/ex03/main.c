#include <stdio.h>
int ft_count_if(char **tab, int length, int (*f)(char *));
int zero_or_one(char *str)
{
	return (str[0] > 'b');
}
int main()
{
	char *strs[4] = {"aminecraft", "btetris", "capex", "dcubase"};
	for (int i = 0; i < 4; i++)
		printf("%s\n", strs[i]);
	printf("ans:%d\n", ft_count_if((char **)strs, 4, &zero_or_one));
}
