
char	*ft_strcat(char *dest, char *src)
{
	int		dest_count;
	int		index;
	char	*return_p;

	dest_count = 0;
	return_p = dest;
	while (*dest != '\0')
	{
		dest++;
		dest_count++;
	}
	index = 0;
	while (index < dest_count)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	printf("%d\n",dest[index]);
	printf("%s\n",return_p);
	return return_p;
}
