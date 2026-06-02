
#include "minishell.h"
#include "atrombel.h"

//pipe_fd[0] = fd de lecture
//pipe_fd[1] = fd d'écriture

void	reset_pipe(t_data *data)
{
	close(data->pipe_fd[1]);
	close(data->pipe_fd[0]);
	data->pipe_fd[1] = -1;
	data->pipe_fd[0] = 0;
}
void	exe_pipeline(t_list *cmd_head, t_data *data, pid_t pid, t_env **env)
{
	if (cmd_head->next)
		pipe(data->pipe_fd);
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
		else
			exit(1)
		exit(126);
	}
	while (waitpid(-1, &status, 0) > 0);
		data->last_exit_status = status;
	dup2(data->pipe_fd[0], data->tmp_fd);
	if (cmd_head->next)
		reset_pipe(data);

}
