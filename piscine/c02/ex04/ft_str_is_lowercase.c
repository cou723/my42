int	ft_str_is_lowercase(char *str)
{
	int	flag;

	if (*str == '\0')
		return (1);
	flag = 1;
	while (*str != '\0')
	{
		if (!(*str >= 'a' && *str <= 'z'))
			flag = 0;
		str++;
	}
	return (flag);
}
