int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (index < ft_strlen(src) + 1)
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}
