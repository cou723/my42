int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	num;
	int	index;

	num = 1;
	index = 0;
	while (++index < length)
		num = num && (f(tab[index - 1], tab[index]) < 0);
	return (num);
}
