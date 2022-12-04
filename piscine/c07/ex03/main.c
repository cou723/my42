#include <stdio.h>
#include <stdlib.h>
char *ft_strjoin(int size, char **strs, char *sep);
int	  main()
{
	char  *ss[4] = {"microsf", "microsffdsaf", "microsf", "microsffdsaffsdsdfdfass"};
	char  split[] = " <<0=-fdfasfddfsadfs-=0>> ";
	char *s = ft_strjoin(4, ss, split);
	printf("%s\n", s);
	free(s);
}
