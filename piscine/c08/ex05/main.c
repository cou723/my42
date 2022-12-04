#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);

int main()
{
	char *ss[] = {"doragon quest", "minecraft", "", "tetris"};

	t_stock_str *p = ft_strs_to_tab(4, (char **)ss);
	ft_show_tab(p);
	free(p);
}
