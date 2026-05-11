
#include "minishell.h"
#include "cgasser.h"
#include <stdlib.h>

void	ft_free_cmd(void *content);
void	ft_free_redirs(void *content);

void	ft_clear_cmds(t_list **cmds)
{
	ft_lstclear(cmds, ft_free_cmd);
}

void	ft_free_cmd(void *content)
{
	t_cmd	*cmd;
	
	cmd = (t_cmd *)content;
	free(cmd->cmd);
	free(cmd->path);
	ft_lstclear(&cmd->flags, free);
	ft_lstclear(&cmd->args, free);
	ft_lstclear(&cmd->redirs, ft_free_redirs);
	free(cmd);
}

void	ft_free_redirs(void *content)
{
	t_redir	*redir;

	redir = (t_redir *)content;
	free(redir->arg);
	free(redir);
}
