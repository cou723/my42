unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	index;
	unsigned int	rtn_size;

	dest_size = ft_strlen(dest);
	rtn_size = dest_size + ft_strlen(src);
	while (*dest != '\0')
		dest++;
	index = 0;
	size -= dest_size;
	while ((rtn_size < size && index < rtn_size - 1)
		|| (rtn_size > size && index < size - 1))
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (rtn_size);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
