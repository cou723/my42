#include <stdio.h>
#define COUNT 6
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int main(void)
{
	char *string1;
	char  string2[2];

	string1 = "0";
	printf("base   : %s\n", string1);
	strlcpy(string2, string1, 0);
	printf("cpy c  : %s\n", string2);
	ft_strlcpy(string2, string1, 0);
	printf("cpy ft : %s\n", string2);
}
