#include<stdio.h>
void	ft_ultimate_ft(int *********nbr);
int main(){int i = 10,*p1 = &i,**p2 = &p1,***p3 = &p2,****p4 = &p3,*****p5 = &p4,******p6 = &p5,*******p7 = &p6,********p8 = &p7,*********p9 = &p8;ft_ultimate_ft(p9);printf("i:%d\n",*********p9);}
