int	ft_iterative_power(int nb, int power)
{
	int	ans;

	if (power < 0)
		return (0);
	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	ans = nb;
	power--;
	while (power > 0)
	{
		ans *= nb;
		power--;
	}
	return (ans);
}
