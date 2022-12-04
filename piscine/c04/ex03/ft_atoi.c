int	is_number(char c)
{
	return ((c >= '0') && (c <= '9'));
}

int	is_p_m(char c)
{
	return (c == '+' || c == '-');
}

int	ft_atoi(char *str)
{
	int		pm;
	int		rtn_int;

	pm = 1;
	rtn_int = 0;
	while (((*str <= ' ') || (*str >= 9 && *str <= 13)) && *str)
		str++;
	while (is_p_m(*str) && *str)
	{
		pm *= -(*str - 44);
		str++;
	}
	while (is_number(*str) && *str)
	{
		rtn_int *= 10;
		rtn_int -= *str - 48;
		str++;
	}
	return (rtn_int * (pm * -1));
}
