
#include "minishell.h"
#include "cgasser.h"

void	ft_fill_cmd(t_cmd *cmd, t_token *token)
{
	char	*word;

	word = NULL;
	word = malloc(sizeof(char) * (ft_strlen(token->word) + 1));
	ft_strlcpy(word, token->word, ft_strlen(token->word) + 1);
	if (token->type == FLAG)
		cmd->flag = ft_arrayadd_back(cmd->flag, word);
	else
		cmd->args = ft_arrayadd_back(cmd->args, word);	
}
