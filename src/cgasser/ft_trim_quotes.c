
#include "minishell.h"

#include "ft_printf.h"

char	*ft_trim_quotes(char *str)
{
	char	*res;
	int		len;

	len = 0;
	res = NULL;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (!ft_isquote(str[0]) || !ft_isquote(str[len - 1]))
		return (str);
	res = ft_calloc(sizeof(char), len - 1);
	if (!res)
		return (perror("ft_trim_quotes: "), NULL);
	ft_strlcpy(res, str + 1, len - 1);
	free(str);
	return (res);
}
