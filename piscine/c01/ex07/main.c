#include<stdio.h>
#include"ft_rev_int_tab.h"
int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	for(unsigned long  i = 0; i < sizeof(a)/sizeof(int); i++){
		printf("%d\n",a[i]);
	}
	ft_rev_int_tab(a, sizeof(a)/sizeof(int));
	for(unsigned long  i = 0; i < sizeof(a)/sizeof(int); i++){
		printf("%d\n",a[i]);
	}
}
