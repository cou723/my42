#include <stdio.h>
void ft_putstr_non_printable(char *str);
int	 main()
{
	char str[] = "\xb5\xfc\xfa\xbcn\x0e*\xd3%\xb0Z\x16\xd2\x1d\xeb&\x0a\xef\x01\x9d-\xb0\x1f\xcf\xac\xc5\xa3\xac<\xd2^>\x08\xcaJ\xc2\xe0\xa2\xbe\xc7\xd9\xf9\xfe\xbc\x98\xdf\xea\xca\xec&\x85";
	ft_putstr_non_printable(str);
}