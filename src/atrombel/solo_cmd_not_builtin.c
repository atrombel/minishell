
#include "minishell.h"
#include "atrombel.h"
#include "cgasser.h"


void	waitpid_operations(t_data *data)
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
		data->last_exit_status = status;
	if (WIFEXITED(status))
		data->last_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
					write(1, "\n", 1);
		else if (WTERMSIG(status) == SIGQUIT)
			write(1, "Quit (core dumped)\n", 19);
		data->last_exit_status = 128 + WTERMSIG(status);
	}
}

void	ft_execute_cmd(t_cmd *cmd, t_env **env)
{
	char	**envp;

	is_minishell_lvl(cmd, env);// rajouter dans multiple pipe;
	envp = env_to_charstar_reconversion(*env);
	if (!envp)
	{
		error_print("ERROR");
		return ;
	}
	set_signals_default();
	execve(cmd->path, cmd->args, envp);
	error_print("execve failed");
	if (errno == EACCES)
		exit(126);
	exit(127);
}

// organise execution of cmd and application of redir
void	ft_execute_cmd_redir(t_cmd	*cmd, t_data *data, t_env **env, t_list *cmd_head)
{
	int	pid;

	set_signals_ignore();
	pid = fork();
	if (pid == -1)
	{
		error_print("fork");
		return ;
	}
	else if(pid == 0)//child
	{
		if (cmd->redirs)// a voir si je peux enelever ceci
		{
			if (ft_redir_apply(cmd_head, data) == 0)
				ft_execute_cmd(cmd, env);
		}
		else
			ft_execute_cmd(cmd, env);
	}
	else if (pid > 0)
		waitpid_operations(data);
}

void	solo_cmd_not_builtin(t_list *cmd_head, t_data *data, t_env **env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)cmd_head->content;
	ft_execute_cmd_redir(cmd, data, env, cmd_head);
	heredoc_tmp_deletion(cmd_head, data);
}
