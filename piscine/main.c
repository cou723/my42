#include <stdio.h>
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	unsigned int count;

	count = 0;
	i = 0;
	while (*(src + i))
	{
		count++;
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (i > count - 1)
		{
			*(dest + i) = '\0';
		}
		else
		{
			*(dest + i) = *(src + i);
		}
		i++;
	}
	return (dest);
}

int main()
{
	char a[] = "hello",b[10];
	ft_strncpy(b,a,3);
	printf("%s\n",b);
	for (size_t i = 0; i < (size_t)sizeof(b)/sizeof(char); i++)
	{
		printf("%ld:%c\n",i,b[i]);
	}

}
