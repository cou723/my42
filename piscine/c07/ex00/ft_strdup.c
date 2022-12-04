#include <errno.h>
#include <stdlib.h>
char	*ft_strdup(char *s)
{
	char	*rtn_str;
	int		s_size;
	int		i;

	s_size = 0;
	while (s[s_size] != '\0')
		s_size++;
	rtn_str = (char *)malloc(sizeof(char) * s_size + 1);
	if (rtn_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		rtn_str[i] = s[i];
		i++;
	}
	rtn_str[i] = '\0';
	return (rtn_str);
}
