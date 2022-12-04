#include<unistd.h>
#include"ft_modules.h"
#include"calc_module.h"
#define TRUE 1
#define FALSE 0

int		is_num_normal(char *num);
int		is_op(char c);

void	calc(int a, int b, void (*f)(int, int))
{
	f(a, b);
}

void	*get_op_module(char op)
{
	if (op == '+')
		return (&put_add);
	if (op == '-')
		return (&put_sub);
	if (op == '*')
		return (&put_multi);
	if (op == '/')
		return (&put_division);
	return (&put_modulo);
}

int	main(int argc, char *argv[])
{
	int	num1;
	int	num2;

	if (argc != 4)
		return (0);
	if (ft_strlen(argv[2]) != 1 || is_op(argv[2][0]) == FALSE)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (is_num_normal(argv[1]))
		num1 = ft_atoi(argv[1]);
	else
		num1 = 0;
	if (is_num_normal(argv[3]))
		num2 = ft_atoi(argv[3]);
	else
		num2 = 0;
	calc(num1, num2, get_op_module(argv[2][0]));
	return (0);
}
