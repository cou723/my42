int	ft_str_is_numeric(char *str)
{
	int	flag;

	if (*str == '\0')
		return (1);
	flag = 1;
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			flag = 0;
		str++;
	}
	return (flag);
}
