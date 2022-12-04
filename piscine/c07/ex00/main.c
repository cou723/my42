#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
char *ft_strdup(char *s);
int	  main()
{
	char *str;
	str = ft_strdup("");
	if(str == NULL)
		printf("get null\n");
	else
		printf("%s\n", str);
	free(str);
	str = ft_strdup("hello 42");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("gdBg8jnV4aqOfzl");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("jjcZhR4nGui5BWOSTZAiTas6I134GiP");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("myKLmUJWNDGRQPYFPAV2MQdP");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("BEM4YUQH");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("EGHGPnis3AbmTVGOCuUByz1lcQS3iVhJsVud01lLgnfUGgeuwr");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("5VjE17r1nx");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("SXBjGc2tgW2aJx9xrpRct6tJhm5jWPxIoBrQ");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("RMg0a5RUF3iXiAmueTK5EVDFBzmnE248AowgTEor");
	printf("%s\n", str);
	free(str);
}
