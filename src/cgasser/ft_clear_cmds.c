
#include "cgasser.h"
#include <stdlib.h>
#include "atrombel.h"

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
	if (cmd->path)
		free(cmd->path);
	if (cmd->args)
		ft_free_array(cmd->args);
	if (cmd->redirs)
		ft_lstclear(&cmd->redirs, ft_free_redirs);
	free(cmd);
}

void	ft_free_redirs(void *content)
{
	t_redir	*redir;

	redir = (t_redir *)content;
	if (redir->arg)
		free(redir->arg);
	if (redir->hd_filename)
		free(redir->hd_filename);
	if (redir->hd_tmp_fd)
		secure_close(&redir->hd_tmp_fd);
	free(redir);
}
