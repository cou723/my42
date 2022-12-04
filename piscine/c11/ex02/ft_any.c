int	ft_any(char **tab, int (*f)(char *))
{
	int	num;

	num = 0;
	while (*tab != 0)
	{
		num = num | f(*tab);
		tab++;
	}
	return (num);
}
