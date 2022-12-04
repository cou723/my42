#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	i = 0;
	while (*(src + i))
	{
		count++;
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (i > count - 1)
			*(dest + i) = '\0';
		else
			*(dest + i) = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count_word_end_p(int i, int i_now, int *arr, int count)
{
	if ((i - i_now) != 0)
	{
		arr[count * 2] = i_now;
		arr[count * 2 + 1] = i - i_now;
		count++;
	}
	return (count);
}

int	count_word(char *str, char *charset, int *arr)
{
	int	count;
	int	i;
	int	wd_start;
	int	j;

	count = 0;
	i = -1;
	wd_start = 0;
	while (str[++i] != '\0')
	{
		j = 0;
		while (charset[j] == str[i + j])
		{
			if (charset[j + 1] == '\0' && (i - wd_start) != 0)
			{
				arr[count * 2] = wd_start;
				arr[(count++) *2 + 1] = i - wd_start;
				wd_start = i + j + 1;
			}
			j++;
		}
	}
	if (count == 0 && ft_strlen(str) == ft_strlen(charset))
		return (0);
	return (count_word_end_p(i, wd_start, arr, count));
}

char	**ft_split(char *str, char *charset)
{
	char	**rtn_strs;
	int		i;
	int		a_list[1024];
	int		ct;

	i = 0;
	ct = count_word(str, charset, a_list);
	rtn_strs = (char **)malloc(sizeof(char *) * (ct + 1));
	while (i < ct)
	{
		rtn_strs[i] = (char *)malloc(sizeof(char *) * (a_list[i * 2 + 1] + 1));
		ft_strncpy(rtn_strs[i], &str[a_list[i * 2]], a_list[i * 2 + 1]);
		i++;
	}
	rtn_strs[i] = NULL;
	return (rtn_strs);
}
