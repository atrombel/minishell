
#include "minishell.h"
#include "atrombel.h"


// void	ft_redir_close(t_data *data)
// {




// }

// applque la redir sinon return 1 si error 0 si tout bon
int	ft_redir_apply(t_list *cmd_head, t_data *data)
{
	t_list	*redirs;
	t_redir	*redir;
	int		error;

	error = 0;
	redirs = ((t_cmd *)cmd_head->content)->redirs;
	while(redirs)
	{
		redir = (t_redir *)redirs->content;
		if (redir->type == IN)
			stdin_redir(redir, data, &error);
		else if (redir->type == OUT)
			stdout_redir(redir, data, &error);
		else if (redir->type == IN_DELIM)
			heredoc_reddir_apply(redir, data, &error);
		else if (redir->type == OUT_APPN)
			stdout_appnd(redir, data, &error);
		if (*error == 1)
			break ;
		redirs = redirs->next;
	}
	return(error);
}

void	fd_redir_restoration_close(t_data *data)
{
	if (data->stdin_save >= 0)
	{
		if (dup2(data->stdin_save, 0) == -1)// to sercure
			error_print("error");
		close(data->stdin_save);
		data->stdin_save = -1;
	}
	if (data->stdout_save >= 0)
	{
		if (dup2(data->stdout_save , 1) == -1)// to sercure
			error_print("error");
		close(data->stdout_save );
		data->stdout_save  = -1;
	}
	if (data->infile != -1)
		close (data->infile);
	data->infile = -1;
	if (data->outfile != -1)
		close (data->outfile);
	data->outfile = -1;
}


void	solo_builtin(t_list *cmd_head, t_data *data, t_env **env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)cmd_head->content;
	if (cmd->redirs)
	{
		data->stdin_save = dup(0);
		data->stdout_save = dup(1);
		if (ft_redir_apply(cmd_head, data) == 0)
			ft_execute_builtin(cmd, data, env, cmd_head);
		fd_redir_restoration(cmd_head, data, cmd);
		heredoc_tmp_deletion(cmd_head)
	}
	else
		ft_execute_builtin(cmd, data, env, cmd_head);
}
