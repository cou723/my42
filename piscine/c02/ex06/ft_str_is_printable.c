int	ft_str_is_printable(char *str)
{
	int	flag;

	if (*str == '\0')
		return (1);
	flag = 1;
	while (*str != '\0')
	{
		if (!(*str >= ' ' && *str <= '~'))
			flag = 0;
		str++;
	}
	return (flag);
}
