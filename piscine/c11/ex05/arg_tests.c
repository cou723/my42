#include"ft_modules.h"
#define TRUE 1
#define FALSE 0

int	is_op(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int	is_nb(char c)
{
	return ((c >= '0') && (c <= '9'));
}

int	is_space(char c)
{
	return ((c <= ' ') || (c >= 9 && c <= 13));
}

int	is_num_normal(char *num)
{
	while (((*num <= ' ') || (*num >= 9 && *num <= 13)))
	{
		if (*num == '\0')
			return (FALSE);
		num++;
	}
	while ((*num == '+' || *num == '-'))
	{
		if (*num == '\0')
			return (FALSE);
		num++;
	}
	if (is_nb(*num))
		return (TRUE);
	return (FALSE);
}
