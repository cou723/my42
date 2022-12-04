#include<stdio.h>
#include"ft_sort_int_tab.h"
int main(){
	int a[] = {1,67,4,345,7,56,234,5,7};
	for(unsigned long  i = 0; i < sizeof(a)/sizeof(int); i++){
		printf("%d, ",a[i]);
	}
	ft_sort_int_tab(a, sizeof(a)/sizeof(int));
	printf("\n");
	for(unsigned long  i = 0; i < sizeof(a)/sizeof(int); i++){
		printf("%d, ",a[i]);
	}
}
