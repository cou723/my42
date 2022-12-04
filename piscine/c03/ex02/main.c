char *ft_strcat(char *dest, char *src);
#include<stdio.h>
#include<string.h>
int main(){
	char a1[8] = "ABC", b1[] = "ABCD";
	printf("ft_strcat:%s\n", ft_strcat(a1, b1));
	printf("a:%s,b:%s\n",a1,b1);
	char a2[8] = "ABC", b2[] = "ABCD";
	printf("strcat   :%s\n", strcat(a2, b2));
	printf("a:%s,b:%s\n",a2,b2);
}
