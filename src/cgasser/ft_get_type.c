
#include "minishell.h"
#include "cgasser.h"

int	ft_get_type(t_token *token)
{
	if (token->index == 0)
	{
		if (ft_check_cmd(token) != 0)
			return (1);
	}
	else if (ft_strncmp(token->word, "-n", 2) == 0 && token->index == 1)
		token->type = FLAG;
	else
		token->type = ARG;
	return (0);
}
