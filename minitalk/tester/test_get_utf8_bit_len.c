#include <stdbool.h>
#include <stdio.h>
#define BYTE 8

unsigned int	get_utf8_bit_len(char byte)
{
	unsigned int	total;

	total = 1;
	if (!(byte >> 7 & 0x1))
		return (BYTE * 1);
	if (byte >> 5 & 0x1)
		total = 3;
	else
		return (2 * BYTE);
	if (byte >> 4 & 0x1)
		total = 4;
	return (BYTE * total);
}

bool	test(char c, unsigned char expect_bit)
{
	static size_t	index = 0;

	index++;
	if (get_utf8_bit_len(c) == expect_bit)
	{
		printf("%lu: successfully\n", index);
		return (true);
	}
	else
	{
		printf("%lu: wrong: actual:%d, expect:%d\n", index, get_utf8_bit_len(c),
				expect_bit);
		return (false);
	}
}

int	main(void)
{
	int	total;

	total = 0;
	total += test('a', 8);
	total += test(0xd1, 16);
	total += test(0xe1, 24);
	total += test(0xf1, 32);
	printf("success:%d/4\n", total);
}
