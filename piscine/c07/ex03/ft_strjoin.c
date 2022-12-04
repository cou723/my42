#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		index;
	char	*return_p;

	return_p = dest;
	while (*dest != '\0')
		dest++;
	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (return_p);
}

int	a_strlen(int strs_ct, char **strs, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < strs_ct)
		count += (ft_strlen(strs[i++]) + ft_strlen(sep));
	return (count - ft_strlen(sep));
}

char	*ft_strjoin(int strs_ct, char **strs, char *sep)
{
	char	*rtn_str;
	int		i;

	rtn_str = (char *)malloc(sizeof(char) * (a_strlen(strs_ct, strs, sep) + 1));
	if (rtn_str == NULL)
		return (NULL);
	i = 0;
	rtn_str[0] = '\0';
	if (strs_ct == 0)
		return (rtn_str);
	while (strs[i] && i < strs_ct)
	{
		rtn_str = ft_strcat(rtn_str, strs[i]);
		i++;
		if (i != strs_ct)
			ft_strcat(rtn_str, sep);
	}
	return (rtn_str);
}
