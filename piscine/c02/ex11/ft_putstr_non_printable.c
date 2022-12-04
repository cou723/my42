#include <unistd.h>
int	ft_char_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

char	convert_10_to_16(unsigned int num)
{
	if (num < (unsigned int)10)
		return (num + ('0'));
	else if (num >= (unsigned int)10 && num < (unsigned int)16)
		return (num - (unsigned int)10 + 'a');
	else
		return (' ');
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	chara;
	char			outputs[2];

	while (*str != '\0')
	{
		if (ft_char_is_printable(*str))
			write(1, str, 1);
		else
		{
			chara = (unsigned char)*str;
			outputs[0] = convert_10_to_16(chara / 16);
			outputs[1] = convert_10_to_16(chara % 16);
			write(1, "\\", 1);
			write(1, outputs, 2);
		}
		str++;
	}
}
