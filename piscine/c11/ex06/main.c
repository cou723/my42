#include<stdio.h>
void ft_sort_string_tab(char **tab);
int main(){
	char *ss[8]={"c","cxx","cs","html","css","js","typescript"};
	ss[7]=NULL;
	for (size_t i = 0; i < sizeof(ss)/sizeof(char*); i++)
		printf("b: %s\n",ss[i]);
	ft_sort_string_tab((char**)ss);
	for (size_t i = 0; i < sizeof(ss)/sizeof(char*); i++)
		printf("a: %s\n",ss[i]);
}
