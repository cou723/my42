char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int dest_count;
	unsigned int index;
	char *		 return_p;

	dest_count = 0;
	return_p = dest;
	while (*dest != '\0')
	{
		dest++;
		dest_count++;
	}
	index = 0;
	if (dest_count > nb)
		dest_count = nb;
	while (index < dest_count)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return return_p;
}
