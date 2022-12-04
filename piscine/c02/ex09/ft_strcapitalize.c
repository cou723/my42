int	is_demliter(char c)
{
	return (!((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9')));
}

char	*ft_strcapitalize(char *str)
{
	int	index;
	int	w_index;

	index = 0;
	w_index = 0;
	while (str[index] != '\0')
	{
		if (w_index == 0 && (str[index] >= 'a' && str[index] <= 'z'))
			str[index] -= 'a' - 'A';
		else if (w_index != 0 && (str[index] >= 'A' && str[index] <= 'Z'))
			str[index] += 'a' - 'A';
		if (is_demliter(str[index]))
			w_index = 0;
		else
			w_index++;
		index++;
	}
	return (str);
}
