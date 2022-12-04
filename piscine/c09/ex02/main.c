char **ft_split(char *str, char *charset);
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	(void)argc;

	char *str;
	int	  index = 0;
	str = argv[1];
	printf("%s\n", str);
	char **ss1 = ft_split(str, argv[2]);
	puts("tab start");
	while (1)
	{
		printf("tab[%d]: %s\n", index, ss1[index]);
		if (ss1[index] == NULL)
			break;
		index++;
	}
	free(ss1);
	puts("tab end");
	printf("str:%s\n\n", str);

	//index = 0;
	//str = ".1,.";
	//printf("%s\n", str);
	//char **ss2 = ft_split(str, ",.");
	//puts("tab start");
	//while (1)
	//{
	//	printf("tab[%d]: %s\n", index, ss2[index]);
	//	if (ss2[index] == NULL)
	//		break;
	//	index++;
	//}
	//free(ss2);
	//puts("tab end");
	//printf("str:%s\n\n", str);
//
	//index = 0;
	//str = ",...,.,,,.";
	//printf("%s\n", str);
	//char **ss3 = ft_split(str, ",.");
	//puts("tab start");
	//while (1)
	//{
	//	printf("tab[%d]: %s\n", index, ss3[index]);
	//	if (ss3[index] == NULL)
	//		break;
	//	index++;
	//}
	//free(ss3);
	//puts("tab end");
	//printf("str:%s\n\n", str);
//
	//index = 0;
	//str = "100,";
	//printf("%s\n", str);
	//char **ss4 = ft_split(str, ",.");
	//puts("tab start");
	//while (1)
	//{
	//	printf("tab[%d]: %s\n", index, ss4[index]);
	//	if (ss4[index] == NULL)
	//		break;
	//	index++;
	//}
	//free(ss4);
	//puts("tab end");
	//printf("str:%s\n\n", str);
//
	//index = 0;
	//str = "100";
	//printf("%s\n", str);
	//char **ss5 = ft_split(str, ",.");
	//puts("tab start");
	//while (1)
	//{
	//	printf("tab[%d]: %s\n", index, ss5[index]);
	//	if (ss5[index] == NULL)
	//		break;
	//	index++;
	//}
	//free(ss5);
	//puts("tab end");
	//printf("str:%s\n\n", str);
//
	//index = 0;
	//str = ",.100";
	//printf("%s\n", str);
	//char **ss6 = ft_split(str, ",.");
	//puts("tab start");
	//while (1)
	//{
	//	printf("tab[%d]: %s\n", index, ss6[index]);
	//	if (ss6[index] == NULL)
	//		break;
	//	index++;
	//}
	//free(ss6);
	//puts("tab end");
	//printf("str:%s\n\n", str);
//
	//index = 0;
	//str = "11,22,33,";
	//printf("%s\n", str);
	//char **ss7 = ft_split(str, ",.");
	//puts("tab start");
	//while (1)
	//{
	//	printf("tab[%d]: %s\n", index, ss7[index]);
	//	if (ss7[index] == NULL)
	//		break;
	//	index++;
	//}
	//free(ss7);
	//puts("tab end");
	//printf("str:%s\n\n", str);
//
	//index = 0;
	//str = "abc,123.ABC";
	//printf("%s\n", str);
	//char **ss8 = ft_split(str, ",.");
	//puts("tab start");
	//while (1)
	//{
	//	printf("tab[%d]: %s\n", index, ss8[index]);
	//	if (ss8[index] == NULL)
	//		break;
	//	index++;
	//}
	//free(ss8);
	//puts("tab end");
	//printf("str:%s\n\n", str);
}
