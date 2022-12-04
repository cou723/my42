char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	if (*to_find == '\0')
		return (str);
	i = -1;
	while (str[++i] != '\0')
	{
		j = -1;
		while (to_find[++j] == str[i + j])
			if (head_strstr(str, to_find[j]))
				return (str);
	}
	return (0);
}
