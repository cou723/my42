#include<stdio.h>
int	j_than_i_large_is(char *i, char *j);
void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));
int main(){
	char *ss[8]={"c","cxx","cs","html","css","js","typescript"};
	ss[7]=NULL;
	for (size_t i = 0; i < sizeof(ss)/sizeof(char*); i++)
		printf("b: %s\n",ss[i]);
	ft_advanced_sort_string_tab((char**)ss,&j_than_i_large_is);
	for (size_t i = 0; i < sizeof(ss)/sizeof(char*); i++)
		printf("a: %s\n",ss[i]);
}
