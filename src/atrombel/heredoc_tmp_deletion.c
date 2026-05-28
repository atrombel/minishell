
#include "minishell.h"
#include "atrombel.h"

void	heredoc_close(t_list *cmd_head, t_list *redirs;)
{
	t_redir *redir;

	redir = redirs->content;
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

// function that find
char	*herdoc_finder( t_list *cmd_head)
{
	t_list *redirs;

	redirs = cmd_head->content->redirs;
	while(redirs)
	{
		if (redirs->content->type == IN_DELIM)
			heredoc_close(cmd_head, redirs);
		redirs = redirs->next;
	}
}

//fonction that delte the heredoc and everything linked to it
void	heredoc_tmp_deletion(t_list *cmd_head)
{
	while(cmd_head)
	{
		heredoc_finder(cmd_head);
		cmd_head = cmd_head->next;
	}

}
