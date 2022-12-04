int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n != 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		else if (*s2 == '\0')
			return ((int)*s1);
		else if (*s1 == '\0')
			return ((int)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
