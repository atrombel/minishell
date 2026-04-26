
#include "minishell.h"
#include "cgasser.h"

int	ft_get_type(t_token *token, char **envp)
{
	int	index;
	char	*word;
	
	index = token->index;
	word = token->word;
	if (index == 0)
	{
		if (ft_check_cmd(token, envp) != 0)
			return (1);
	}
	else if (word[0] == '-' && word[1] != '\0' && index == 1)
		token->type = FLAG;
	else
		token->type = ARG;
	return (0);
}
