
#include "minishell.h"
#include "ft_printf.h"

int	ft_find_next_word(char const *s, char c, int index);
int	ft_strlen_word_quoted(char const *s, char c, int index);
int	ft_count_word_quoted(char const *s, char c);
char	*ft_strchr_quoted(const char *s, int c);

//regular split from the libft, that jump the quoted "" or '' sequences
//allocate memory (using malloc(3)) and returns an array of strings obtained by
//splitting 's' using the character 'c' as a delimiter. The array must end with
//a NULL pointer.

char	**ft_split_quoted(char const *s, char c)
{
	int		i;
	int		j;
	int		len_word;
	char	**res;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	res = ft_calloc(sizeof(char *), ft_count_word_quoted(s, c) + 1);
	if (!res)
		return (NULL);
	i = ft_find_next_word(s, c, i);
	while (s[i] != '\0')
	{
		len_word = ft_strlen_word_quoted(s, c, i);
		res[j] = ft_calloc(sizeof(char), (len_word + 1));
		if (!res[j])
			return (ft_free_array(res), NULL);
		ft_strlcpy(res[j], s + i, len_word + 1);
		i += len_word;
		i = ft_find_next_word(s, c, i);
		j++;
	}
	return (res);
}

int	ft_find_next_word(char const *s, char c, int index)
{
	while (s[index] == c)
		index++;
	return (index);
}

int	ft_strlen_word_quoted(char const *s, char c, int index)
{
	char const	*start;
	char		*end;

	start = s + index;
	end = NULL;
	if (*start == 34)
	{
		end = ft_strchr(start + 1, 34);
		if (end)
			end++;
	}
	else if (*start == 39)
	{
		end = ft_strchr(start + 1, 39);
		if (end)
			end++;
	}
	else
		end = ft_strchr_quoted(start, c);
	if (!end)
		return (ft_strlen(start));
	return (end - start);
}

int	ft_count_word_quoted(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i = ft_find_next_word(s, c, i);
		if (s[i] != '\0')
			count++;
		i += ft_strlen_word_quoted(s, c, i) + 1;
	}
	return (count);
}

char	*ft_strchr_quoted(const char *s, int c)
{
	int		i;
	char	*res;
	char	cc;

	cc = (char) c;
	i = 0;
	while (s[i] != '\0' && s[i] != cc && s[i] != 39 && s[i] != 34 )
		i++;
	if (s[i] == cc || s[i] != 39 || s[i] != 34)
	{
		res = (char *)&s[i];
		return (res);
	}
	else
		return (NULL);
}

/*
#include "libft.h"

int	main()
{
	char	*s = "hello!";
	char	c = 0;
	char	**res;
	int	i;

	res = ft_split(s, c);

	i = 0;
	while (res[i] != NULL)
	{
		printf("'%s' ", res[i]);
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
	res = NULL;
}*/
