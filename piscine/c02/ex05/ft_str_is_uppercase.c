int	ft_str_is_uppercase(char *str)
{
	int	flag;

	if (*str == '\0')
		return (1);
	flag = 1;
	while (*str != '\0')
	{
		if (!(*str >= 'A' && *str <= 'Z'))
			flag = 0;
		str++;
	}
	return (flag);
}
