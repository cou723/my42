unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb);
#include<stdio.h>
#include<string.h>
#define NUM1 4
#define NUM2 10
int main(){
	char a1[NUM1] = "ABC", b1[] = "ABCDE";
	printf("ft_strlcat:%d\n", ft_strlcat(a1, b1 , NUM1));
	printf("a:%s,b:%s\n",a1,b1);

	char a2[NUM2] = "ABC", b2[] = "ABCDE";
	printf("ft_strlcat:%d\n", ft_strlcat(a2, b2 , NUM2));
	printf("a:%s,b:%s\n",a2,b2);

	char a3[NUM1] = "ABC", b3[] = "ABCDE";
	printf("   strlcat:%d\n", strlcat(a3, b3 , NUM1));
	printf("a:%s,b:%s\n",a3,b3);

	char a4[NUM2] = "ABC", b4[] = "ABCDE";
	printf("   strlcat:%d\n", strlcat(a4, b4 , NUM2));
	printf("a:%s,b:%s\n",a4,b4);
}
