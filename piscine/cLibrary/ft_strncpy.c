char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (i > n)
		i = n;
	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	if (i < n)
		dest[j] = '\0';
	return dest;
}
