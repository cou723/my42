void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	t;

	i = 0;
	size--;
	while (i < size / 2)
	{
		t = tab[i];
		tab[i] = tab[size - i];
		tab[size - i] = t;
		i++;
	}
}
