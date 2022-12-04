char	*ft_strncpy(char *dest, char *src, unsigned int copy_size)
{
	unsigned int	src_index;
	unsigned int	copied_size;

	src_index = 0;
	while (src[src_index] != '\0')
		src_index++;
	copied_size = 0;
	while (copied_size < src_index && copied_size < copy_size)
	{
		dest[copied_size] = src[copied_size];
		copied_size++;
	}
	while (copied_size < copy_size)
		dest[copied_size++] = '\0';
	return (dest);
}
