#include<stdio.h>
#include<limits.h>
void ft_putnbr_base(int nbr, char *base);
int main(){
	ft_putnbr_base(15,"x");
	puts("");
	ft_putnbr_base(15,"01");
	puts("");
	ft_putnbr_base(100,"01234567");
	puts("");
	ft_putnbr_base(-100,"01234567");
	puts("");
	ft_putnbr_base(INT_MAX,"0123456789");
	puts("");
	ft_putnbr_base(INT_MIN,"0123456789");
	puts("");
	ft_putnbr_base(INT_MAX,"01");
	puts("");
	ft_putnbr_base(INT_MIN,"01");
	puts("");
	ft_putnbr_base(INT_MAX,"01234567");
	puts("");
	ft_putnbr_base(0,"0123456789");
	puts("");
}
