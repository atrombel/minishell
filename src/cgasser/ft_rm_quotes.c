
#include "minishell.h"

int	ft_strlen_unquoted(char *str);
void	ft_strcpy_unquoted(char *res, char *str);

char	*ft_rm_quotes(char *str)
{
	char	*res;

	res = NULL;
	if (!str)
		return (NULL);
	res = ft_calloc(sizeof(char), ft_strlen_unquoted(str) + 1);
	if (!res)
		return (free(str), perror("ft_rm_quotes"), NULL);
	ft_strcpy_unquoted(res, str);
	free(str);
	return (res);
}

int	ft_strlen_unquoted(char *str)
{
	int	i;
	int	count;
	int	quote;

	i = 0;
	count = 0;
	quote = 0;
	while (str[i] != '\0')
	{
		if (quote == 0 && ft_isquote(str[i]))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		else
			count++;
		i++;
	}
	return (count);
}

void	ft_strcpy_unquoted(char *res, char *str)
{
	int		i;
	int		j;
	int		quote;

	i = 0;
	j = 0;
	quote = 0;
	while (str[i] != '\0')
	{
		if (quote == 0 && ft_isquote(str[i]))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		else
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
}
