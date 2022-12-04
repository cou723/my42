#include<stdio.h>
#define TRUE 1
#define FALSE 0
int	get_base(char *base)
{
	int	count;

	count = 0;
	base--;
	while (*++base != '\0')
		count++;
	return (count);
}

int	is_base_normal(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		if (base[i] == '+' || base[i] == '-')
			return (FALSE);
		while (j < get_base(base))
		{
			if (!(i == j) && base[i] == base[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (FALSE);
	return (TRUE);
}

int	get_i_frm_str(char *base, char c)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		//printf("%c:%c\n",base[index],c);
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		rtn_int;
	int		pm;

	pm = 1;
	rtn_int = 0;
	if (!is_base_normal(base))
		return (0);
	while (((*str <= ' ') || (*str >= 9 && *str <= 13)) && *str)
		str++;
	while ((*str == '+' || *str == '-') && *str)
	{
		pm *= -(*str - 44);
		str++;
	}
	while (get_i_frm_str(base, *str) != -1 && *str)
	{
		rtn_int *= get_base(base);
		rtn_int += get_i_frm_str(base, *str);
		str++;
	}
	return (rtn_int * pm);
}
