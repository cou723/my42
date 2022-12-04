#include <unistd.h>
#define UCHAR unsigned char
char	convert_10_to_16(char num)
{
	if (num >= 0 && num < 10)
		return (num + ('0'));
	else if (num >= 10 && num < 16)
		return (num - 10 + 'a');
	else
		return ('0');
}

char	*convert_10_to_16_addres(unsigned long int num, char *str_ptr)
{
	char	*result_str;
	int		i;

	i = 0;
	result_str = &str_ptr[16];
	while (i < 16)
	{
		if (num)
		{
			*--result_str = num % 16;
			if (10 > *result_str)
				*result_str += '0';
			else
				*result_str += ('a' - 10);
			num /= 16;
		}
		else
			*--result_str = '0';
		i++;
	}
	return (str_ptr);
}

void	put(int count, int i, void *p)
{
	if (count < 16 && i > count)
		write(1, "  ", 2);
	else
	{
		write(1, &"0123456789abcdef"[(UCHAR)(*(UCHAR *)p) / 16], 1);
		write(1, &"0123456789abcdef"[(UCHAR)(*(UCHAR *)p) % 16], 1);
	}
}

void	put_line(void *p, int count)
{
	unsigned long int	num;
	char				buf[17];
	int					i;
	char				out_str[17];

	num = (unsigned long int)p;
	write(1, convert_10_to_16_addres(num, buf), 16);
	write(1, ": ", 2);
	i = 0;
	while (i < 16)
	{
		out_str[i] = (char)(*(char *)p);
		if (!(out_str[i] >= ' ' && out_str[i] <= '~'))
			out_str[i] = '.';
		put(count, i, p);
		p++;
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	write(1, out_str, count);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	void	*return_p;

	return_p = addr;
	i = size;
	while (i > 0)
	{
		if (i < 16)
			put_line(addr, i - 1);
		else
			put_line(addr, 16);
		i -= 16;
		addr += 16;
	}
	return (return_p);
}
