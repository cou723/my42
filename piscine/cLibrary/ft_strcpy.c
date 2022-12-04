char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (src[i] != '\0')
		i++;
	j = 0;
	while (j < i+1){
		dest[j] = src[j];
		j++;
	}
	return dest;
}
