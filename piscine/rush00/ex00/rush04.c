#define RIGHT_UP 'C'
#define RIGHT_BOTTOM 'A'
#define LEFT_UP 'A'
#define LEFT_BOTTOM 'C'
#define WALL_HORIZONTAL 'B'
#define WALL_VERTICAL 'B'
#define INSIDE ' '
#define RETURN '\n'

char	rectangle_row(int x, int y, int horizontal, int vertical);

char	upper_side(int x, int horizontal, int vertical)
{
	if (horizontal == 1)
	{
		ft_putchar(LEFT_UP);
		ft_putchar(RETURN);
		if (vertical == 1)
			return ('\0');
		else
			return (rectangle_row(1, 2, horizontal, vertical));
	}
	if (x == 1 && horizontal != 1)
	{
		ft_putchar(LEFT_UP);
		return (upper_side(x + 1, horizontal, vertical));
	}
	else if (x == horizontal)
	{
		ft_putchar(RIGHT_UP);
		ft_putchar(RETURN);
		if (vertical == 1)
			return ('\0');
		else
			return (rectangle_row(1, 2, horizontal, vertical));
	}
	ft_putchar(WALL_HORIZONTAL);
	return (upper_side(x + 1, horizontal, vertical));
}

char	bottom_side(int x, int horizontal, int vertical)
{
	if (horizontal == 1)
	{
		ft_putchar(LEFT_BOTTOM);
		return ('\0');
	}
	else if (x == horizontal)
	{
		ft_putchar(RIGHT_BOTTOM);
		ft_putchar(RETURN);
		return ('\0');
	}
	if (x == 1)
	{
		ft_putchar(LEFT_BOTTOM);
	}
	else
	{
		ft_putchar(WALL_HORIZONTAL);
	}
	return (bottom_side(x + 1, horizontal, vertical));
}

char	rectangle_row(int x, int y, int horizontal, int vertical)
{
	if (y == vertical)
	{
		return (bottom_side(1, horizontal, vertical));
	}
	if (x == horizontal)
	{
		ft_putchar(WALL_VERTICAL);
		ft_putchar(RETURN);
		return (rectangle_row(1, y + 1, horizontal, vertical));
	}
	else if (x == 1)
	{
		ft_putchar(WALL_VERTICAL);
		return (rectangle_row(x + 1, y, horizontal, vertical));
	}
	ft_putchar(INSIDE);
	return (rectangle_row(x + 1, y, horizontal, vertical));
}
