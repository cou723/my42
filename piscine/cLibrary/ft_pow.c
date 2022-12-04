int	pow(int base, int count)
{
	int	num;

	if (count == 0)
		return (1);
	num = base;
	while (count > 1)
	{
		num = num * base;
		count--;
	}
	return (num);
}
