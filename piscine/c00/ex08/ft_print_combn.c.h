#include<unistd.h>
#include<stdio.h>
int	re(int i, int n, int r, char *str);
void	ft_print_combn(int n)
{
	char	str[252][11];

	re(1, 0, n, str);
}
//i:	現在処理している桁
//n:	現在出力している数値
//r:	合計桁
//str:	桁数
//1:1,2,3,4,5,6,7,8,9
int	re(int i, int n, int r, char **str)
{
	printf("i:%d,n:%d,r:%d\n",i,n,r);
	//最後の桁を処理している時
	if (i == r)
	{
		return 0;
	}
	//最後の桁じゃない時
	while (n < 10)
	{
		str[n][i] = '0'+i;
	}
	return re(i, n++, r, str);
}
