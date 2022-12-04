#include "./libs/libft/libft.h"
#include "srcs/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	char	*p;

	p = "-12";
	PRINT(" --- Return : %d\n", PRINT("[%p]\n", p));
	return (0);
}
