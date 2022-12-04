char	*ft_strlowcase(char *str)
{
	int		i;

	if (*str == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ('a' - 'A');
		i++;
	}
	return (str);
}
