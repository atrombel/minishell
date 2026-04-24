
#include "minishell.h"
#include "cgasser.h"

int	ft_get_type(t_token *token, char **envp)
{
	if (token->index == 0)
	{
		if (ft_check_cmd(token, envp) != 0)
			return (1);
	}
	else if (ft_strncmp(token->word, "-", 1) == 0 && token->index == 1)
		token->type = FLAG;
	else
		token->type = ARG;
	return (0);
}
