#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100
struct s_stock_str *ft_strs_to_tab(int ac, char **av);

int main()
{
	char *ss[MAX_LENGTH] = {"x","abc","","01234567890123456789012345678901234567890123456789012345678901234567890123456789"};
	//for (size_t i = 0; i < MAX_LENGTH; i++)
	//	ss[i] = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";
	//*ss = NULL;
	for (int i = 0; i < 4; i++)
		printf("ss[%d]: %s(%p)\n", i, ss[i], ss[i]);
	t_stock_str *p = ft_strs_to_tab(4, (char **)ss);
	if (p == NULL)
	{
		printf("null\n");
		return 0;
	}
	else
	{
		int i = 0;
		while(1)
		{
			printf("---(%p)(i:%d)---\n", &p[i],i);
			printf("\tsize:%d\n", p[i].size);
			printf("\tstr:%s(%p)\n", p[i].str, p[i].str);
			printf("\tcopy:%s(%p)\n", p[i].copy, p[i].copy);
			free(p[i].copy);

			if(p[i].str == NULL)
				break;
			i++;
		}
	}
	free(p);
}
