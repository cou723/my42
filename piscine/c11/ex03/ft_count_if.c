int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (index < length)
	{
		if(f(tab[index]))
			count++;
	}
	return (count);
}
