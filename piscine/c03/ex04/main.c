#include <stdio.h>
#include <string.h>
char *ft_strstr(char *str, char *to_find);
int	  main()
{
	char  s1[] = "abcdefghijklmn";	   /* 検索対象文字列 */
	char  s2[] = "defgh";			   /* 一致する場合 */
	char  s3[] = "xyz";				   /* 一致しない場合 */
	char  s4[] = "abcdefghijklmnopqr"; /* 検索対象文字列より長い場合 */
	char  s5[] = "";				   /* \0 */
	char *sp;

	sp = strstr(s1, s2);
	printf("一致する場合 : %s\n", sp);
	sp = strstr(s1, s3);
	printf("一致しない場合 : %s\n", sp);
	sp = strstr(s1, s4);
	printf("検索対象文字列より長い場合 : %s\n", sp);
	sp = strstr(s1, s5);
	printf("\\0 : %s\n\n", sp);

	sp = ft_strstr(s1, s2);
	printf("一致する場合 : %s\n", sp);
	sp = ft_strstr(s1, s3);
	printf("一致しない場合 : %s\n", sp);
	sp = ft_strstr(s1, s4);
	printf("検索対象文字列より長い場合 : %s\n", sp);
	sp = ft_strstr(s1, s5);
	printf("\\0 : %s\n", sp);
}
