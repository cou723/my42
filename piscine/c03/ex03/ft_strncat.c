unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = -1;
	while (str[++i] != '\0')
		;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	char			*return_p;

	return_p = dest;
	while (*dest != '\0')
		dest++;
	index = 0;
	while (((ft_strlen(src) >= nb) && index < nb)
		|| (!(ft_strlen(src) >= nb) && src[index] != '\0'))
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (return_p);
}
