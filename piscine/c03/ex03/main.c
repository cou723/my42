char *ft_strncat(char *dest, char *src, unsigned int nb);
#include<stdio.h>
#include<string.h>
int main(){
	char a1[6] = "ABC", b1[] = "DEFG";
	printf("ft_strncat:%s\n", ft_strncat(a1, b1 , 2));
	printf("a:%s,b:%s\n",a1,b1);
	char a2[6] = "ABC", b2[] = "DEFG";
	printf("strncat   :%s\n", strncat(a2, b2, 2));
	printf("a:%s,b:%s\n",a2,b2);
}
