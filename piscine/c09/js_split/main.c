char **ft_split(char *str, char *charset);
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int	   index = 0;
	char   str1[] = "012345,,,,,,, 789";
	char   sep[] = "#";
	puts("--test1--");
	char **ss1 = ft_split(str1, sep);
	while (ss1[index] != NULL)
	{
		printf("str: %s\n", ss1[index]);
		index++;
	}
	free(ss1);
	puts("---------");

	index = 0;
	char   str2[] = "1,  12  , 12";
	puts("--test2--");
	char **ss2 = ft_split(str2, sep);

	while (ss2[index] != NULL)
	{
		printf("str: %s\n", ss2[index]);
		index++;
	}
	free(ss2);
	puts("---------");

	index = 0;
	char   str3[] = "1, 2, ";
	puts("--test3--");
	char **ss3 = ft_split(str3, sep);
	while (ss3[index] != NULL)
	{
		printf("str: %s\n", ss3[index]);
		index++;
	}
	free(ss3);
	puts("---------");

	index = 0;
	char   str4[] = ", ";
	puts("--test4--");
	char **ss4 = ft_split(str4, sep);

	while (ss4[index] != NULL)
	{
		printf("str: %s\n", ss4[index]);
		index++;
	}
	free(ss4);
	puts("---------");

	//index = 0;
	//puts("--test5--");
	//char   str5[10]= ", ";
	//char **ss5 = ft_split(str5, sep);
	//while (ss5[index] != NULL)
	//{
	//	printf("str: %s\n", ss5[index]);
	//	index++;
	//}
	//free(ss5);
	//puts("---------");

}
