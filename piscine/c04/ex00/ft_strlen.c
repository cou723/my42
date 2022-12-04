int	ft_strlen(char *str)
{
	int	count;

	count = 0 - 1;
	while (str[++count] != '\0')
		;
	return (count);
}
