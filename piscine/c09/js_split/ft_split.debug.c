#include <stdio.h>
#include <stdlib.h>
#define START_C count * 2
#define LEN_C count * 2 + 1
#define START_I i * 2
#define LEN_I i * 2 + 1
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	unsigned int count;

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

int count_word_end_p(int i, int i_now, int *arr, int count)
{
	if ((i - i_now) != 0)
	{
		arr[START_C] = i_now;
		arr[LEN_C] = i - i_now;
		count++;
	}
	return (count);
}

int count_word(char *str, char *charset, int *arr)
{
	int count;
	int i;
	int wd_start;
	int j;

	count = 0;
	i = -1;
	wd_start = 0;
	while (str[++i] != '\0')
	{
		//printf("i%d\n",i);
		j = 0;
		while (charset[j] == str[i + j])
		{
			//puts("j");
			if (charset[j + 1] == '\0' && (i - wd_start) != 0)
			{
				printf("f s:%d,e:%d\n", wd_start, i - wd_start);
				arr[START_C] = wd_start;
				arr[LEN_C] = i - wd_start;
				count++;
				wd_start = i + j + 1;
			}
			j++;
		}
	}
	if (count == 0 && ft_strlen(str) == ft_strlen(charset))
		return (0);
	return (count_word_end_p(i, wd_start, arr, count));
}

char **ft_split(char *str, char *charset)
{
	char **rtn_strs;
	int i;
	int a_list[1024];

	i = 0;
	int ct = count_word(str, charset, a_list);
	rtn_strs = (char **)malloc(sizeof(char *) * (ct + 1));
	printf("ct:%d\n", ct);
	while (i < ct)
	{
		printf("m s:%d,e:%d\n", a_list[START_I], a_list[LEN_I]);
		rtn_strs[i] = (char *)malloc(sizeof(char *) * (a_list[LEN_I] + 1));
		ft_strncpy(rtn_strs[i], &str[a_list[START_I]], a_list[LEN_I]);
		printf("str: <%s>\n", rtn_strs[i]);
		puts("");
		i++;
	}
	rtn_strs[i] = NULL;
	return (rtn_strs);
}
