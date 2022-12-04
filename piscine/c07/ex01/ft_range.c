#include <stdlib.h>
int	*ft_range(int min, int max)
{
	int	*rtn_arr;
	int	i;

	if (min >= max)
		return (NULL);
	rtn_arr = (int *)malloc(sizeof(int) * (max - min));
	if (rtn_arr == NULL)
		return (NULL);
	i = 0;
	while (min != max)
	{
		rtn_arr[i] = min;
		min++;
		i++;
	}
	return (rtn_arr);
}
