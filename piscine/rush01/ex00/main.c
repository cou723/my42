/*
各ファイル説明
split_space.c:preprocessing.cで使われる関数がある。主にスペース区切りでエラー検出する用の関数
put.c:出力用の関数がある。
main.c:main関数があるファイル
*/

#include <stdio.h>
#define MAP_LENGTH 4
void	putstr(char *str);
void	put_error();
int		is_convertible_int(char c);

// 全体の流れ
// step1.加工する前処理 : preprocessing
// 引数が正しいかを精査しながら、引数をint型の配列へと変換するstep
// - 引数は二つか: int is_argument_two(int argc);
// - 第二引数をスペース区切りにする: int* split_to_space_delimiter(char *str)
// - 第二引数が<一桁の数字 一桁の数字 ...>か: int is_argument_string_normal(char *str)
// - 16個すべての数字が<0>以上<マップの辺の長さ>以下で、かつ対角同士（col1upとcol1downなど）の合計が<マップの辺の長さ+1>以下か:int is_all_number_normal(int *array)

// step2.二次元配列(ans[][])に答えを格納

// step3.ans[][]を出力

// Two arguments?
int	is_argument_two(int argc)
{
	return (argc == 2);
}

// Space delimited and converted to int type
void	split_space_to_int(char *str, int *ans)
{
	while (*str != '\0')
	{
		*ans = *str - '0';
		ans++;
		str++;
	}
}

// Judge Single digit number Space Single digit number ...
// & Are all the numbers within regulations(0~9)?
int	is_argument_string_normal(char *str)
{
	int		i;
	char	*x;

	i = 0;
	x = str;
	while (*x != '\0')
	{
		if (i % 2 == 0 && !(is_convertible_int(*x)))
			return (0);
		if (i % 2 == 1 && *x != ' ')
			return (0);
		i++;
		x++;
	}
	if (i > 31 || i < 31)
		return (0);
	return (1);
}

int main(int argc, char *argv[])
{
	//与えられたデータの精査
	int		data[1024];
	int		*data_p;
	char	*arg_str = argv[1];

	data_p = &data[0];

	if (!(is_argument_two(argc)))
		put_error();
	else if (!(is_argument_string_normal(arg_str)))
		put_error();
	//else
	//	split_space_to_int(arg_str, data_p);

	//計算

	//出力
}
