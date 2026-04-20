

#include "minishell.h"
#include "cgasser.h"
#include <stdlib.h>

t_cmd	*ft_new_cmd(char *word)
{
	t_cmd	*cmd;

	cmd = NULL;
	cmd = malloc(sizeof(t_cmd));
	cmd->cmd = NULL;
	cmd->flag = NULL;
	cmd->args = NULL;
	cmd->cmd = malloc(sizeof(char) * (strlen(word) + 1));
	ft_strlcpy(cmd->cmd, word, strlen(word) + 1);
	return (cmd);
}
