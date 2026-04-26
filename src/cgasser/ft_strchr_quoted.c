

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;
	char	cc;

	cc = (char) c;
	i = 0;
	while (s[i] != '\0' && s[i] != cc)
		i++;
	if (s[i] == cc)
	{
		res = (char *)&s[i];
		return (res);
	}
	else
		return (NULL);
}
