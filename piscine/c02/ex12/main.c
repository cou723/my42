#include <stdio.h>
#include <stdlib.h>
void *ft_print_memory(void *addr, unsigned int size);
int   main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;
	char str[] = "string";
	int  count = atoi(argv[1]);
	ft_print_memory(str, count);
}
