#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>

bool	is_only_num(char *str);

int	main(int argc, char const *argv[])
{
	if (argc == 0)
		ft_printf(ERROR_MESSAGE);
	if (!is_numeric(argv))
		ft_printf(ERROR_MESSAGE);
	return (0);
}

bool	is_only_num(char *str)
{
	while (*str != '\0')
	{
		if (!('0' <= *str && *str <= '9'))
			return (false);
		str++;
	}
	return (true);
}

size_t	int_digit(int num)
{
	size_t	digit;

	digit = 0;
	if (num == 0)
		return (1);
	while (num /= 10)
	{
		digit++;
	}
}

bool	try_atoi(const char *str)
{
	if (ft_strlen(str) >= int_digit(INT_MAX))
}