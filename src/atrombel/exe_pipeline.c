
#include "minishell.h"
#include "atrombel.h"

//pipe_fd[0] = fd de lecture
//pipe_fd[1] = fd d'écriture

void	exe_pipeline(t_list *cmd_head, t_data *data, pid_t pid, t_env **env)
{
	if (cmd_head->next)
		pipe(data->pipe_fd[2])
	pid = fork();
	if (pid == 0)
	{
		if (data->tmp_fd != -1)
		{
			dup2(data->tmp_fd, STDIN_FILENO);
			close(data->tmp_fd);
		}
		if (cmd_head->next)
		{
			dup2(data->pipe_fd[1], STDOUT_FILENO);
			close(data->pipe_fd[1]);
			close(data->pipe_fd[0]);
		}
		if (ft_redir_apply(cmd_head, data) == 0)
			solo_cmd(cmd_head, data, env);
	}
	close(data->pipe_fd[1]);
	data->tmp_fd = data->pipe_fd[1];
	close(data->pipe_fd[0]);
}
