int	contains_space(char *str)
{
	while (*str != '\0')
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}


int	is_convertible_int(char c)
{
	return (c >= '0' && c <= '9');
}
