char	*ft_strcat(char *dest, char *src)
{
	int		index;
	char	*return_p;

	return_p = dest;
	while (*dest != '\0')
		dest++;
	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (return_p);
}
