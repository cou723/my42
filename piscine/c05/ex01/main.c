#include<stdio.h>
int ft_recursive_factorial(int nb);
int ft_atoi(char *str);
int main(int argc,char *argv[]){
	if(argc != 2){
		return 0;
	}
	printf("%d\n",ft_recursive_factorial(ft_atoi(argv[1])));
}
