
#include "cgasser.h"
#include "ft_printf.h"

int	ft_len_quote(char *start);
int	ft_len_oper(char *start);
int	ft_len_word(char *start, int c);

int	ft_len_word_quoted(char *s, char c, int index)
{
	char	*start;
	int		len;

	start = s + index;
	len = 0;
	len = ft_len_quote(start);
	if (len == 0)
		len = ft_len_oper(start);
	if (len == 0)
		len = ft_len_word(start, c);
	return (len);
}

int	ft_len_quote(char *start)
{
	char	*end;

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
	if (!end)
		return (0);
	return (end - start);
}

int	ft_len_oper(char *start)
{
	if (ft_strncmp(start, "|", 1) == 0 || ft_strncmp(start, "<", 1) == 0 \
		|| ft_strncmp(start, ">", 1) == 0 || ft_strncmp(start, "=", 1) == 0)
			return (1);
	if (ft_strncmp(start, ">>", 2) == 0 || ft_strncmp(start, "<<", 2) == 0)
			return (2);
	return (0);
}

int	ft_len_word(char *start, int c)
{
	int	len;

	len = 0;
	while (start[len] != '\0' && start[len] != c && !ft_isquote(start[len]) && \
		start[len] != '|' && start[len] != '<' && start[len] != '>' \
		&& start[len] != '=')
		len++;
	return (len);
}
