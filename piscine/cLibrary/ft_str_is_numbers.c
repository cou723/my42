int	ft_str_is_numeric(char *str)
{
	int	i;
	int flag;

	if (*str == '\0')
		return (1);
	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			flag = 0;
		i++;
	}
	return (flag);
}
