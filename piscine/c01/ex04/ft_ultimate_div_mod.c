void	ft_ultimate_div_mod(int *a, int *b)
{
	int	ans;

	ans = *a / *b;
	*b = *a % *b;
	*a = ans;
}
