
#include "minishell.h"
#include "atrombel.h"

//expl cat < po.c
void	stdin_redir(t_redir	*redir, t_data *data, int *error)
{
	data->infile = open(redir->arg, O_RDONLY);
	if (data->infile < 0)
	{
		error_print(redir->arg);
		data->last_exit_status = 1;
		*error = 1;
		return ;
	}
	dup2(data->infile, 0);
	close(data->infile)
}

void	stdout_redir(t_redir	*redir, t_data *data, int *error)
{
	data->outfile = open(redir->arg, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfile < 0)
	{
		error_print(redir->arg);
		data->last_exit_status = 1;
		*error = 1;
		return ;
	}
	dup2(data->outfile, 1);
	close(data->outfile)
}

void	stdout_appnd(t_redir	*redir, t_data *data, int *error)
{
	data->outfile = open(redir->arg, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (data->outfile < 0)
	{
		error_print(redir->arg);
		data->last_exit_status = 1;
		*error = 1;
		return ;
	}
	dup2(data->outfile, 1);
	close(data->outfile)
}

void	heredoc_reddir_apply(t_redir	*redir, t_data *data, int *error)
{


}
