
#include "minishell.h"
#include "cgasser.h"
#include "ft_printf.h"

t_token	*ft_tokenize(char *str, int index)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->word = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strlcpy(token->word, str, ft_strlen(str) + 1);
	token->index = index;
	if (ft_get_type(token) != 0)
		return (free(token), NULL);
	return (token);
}
