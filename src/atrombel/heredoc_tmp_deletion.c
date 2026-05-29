
#include "minishell.h"
#include "atrombel.h"

void	heredoc_close(t_redir *redir)
{

	if (redir->type == IN_DELIM)
	{
		if (redir->hd_filename)
		{
			if (unlink(redir->hd_filename) == -1)
				perror("unlink");
			if (redir->hd_tmp_fd >= 0)
				close(redir->hd_tmp_fd);
		}
	}
}

// function that find if there is a heredoc associated to the function
void	heredoc_close_cmd ( t_list *cmd_head)
{
	if (!cmd_head || !(t_cmd)cmd_head->content)
		return;
	t_list *redirs;
	t_redir *redir;

	redirs = ((t_cmd *)cmd_head->content)->redirs;
	while(redirs)
	{
		redir = (t_redir *)redirs->content;
		if (redir->type == IN_DELIM)
			heredoc_close(redir);
		redirs = redirs->next;
	}
}

//fonction that delte the heredoc and everything linked to it
void	heredoc_tmp_deletion(t_list *cmd_head)
{
	while(cmd_head)
	{
		heredoc_close_cmd(cmd_head);
		cmd_head = cmd_head->next;
	}

}
