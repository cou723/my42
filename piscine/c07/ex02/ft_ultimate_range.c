#include <stdlib.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int	*rtn_arr;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	rtn_arr = (int *)malloc(sizeof(int) * (max - min));
	if (rtn_arr == NULL)
		return (-1);
	i = 0;
	while (min != max)
	{
		rtn_arr[i] = min;
		min++;
		i++;
	}
	*range = rtn_arr;
	return (i);
}
