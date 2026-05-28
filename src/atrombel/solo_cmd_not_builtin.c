
#include "minishell.h"
#include "atrombel.h"

void	ft_execute_cmd(t_data *data, t_env **env, t_list *head)
{
	char	**envp;

	envp = env_to_charstar_reconversion(env);
	if (!envp)
	{
		error_print("ERROR");
		return ;
	}
	execve(head->content->path, head->content->arg, envp);
	error_print("execve failed");
	//
	//clean_all_there_is_to_clean();
	// exit();
}

void	ft_execute_solo_cmd(t_data *data, t_env **env, t_list *head, int error)
{
	int	pid;
	int	status;

	pid = 0;
	pid = fork();
	if(pid == 0)//child
	{
		ft_execute_cmd(content, data, env);
	}
	if (pid == -1)
	{
		error_print("fork");
		return ;
	}
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			data->last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			data->last_exit_status = 128 + WTERMSIG(status);
	}
}




void	ft_fork_solo_cmd(t_data *data, t_env **env, t_list *head)
{
	int	pid;
	int	status;

	pid = fork();
	if(pid == 0)//child
	{
		if (ft_redir_apply(cmd_head, data) == 0)
			ft_execute_cmd(content, data, env);
	}
	if (pid == -1)
	{
		error_print("fork");
		return ;
	}
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			data->last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			data->last_exit_status = 128 + WTERMSIG(status);
	}
}

void	solo_cmd_not_builtin(t_list *cmd_head, t_data *data, t_env **env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)cmd_head->content;
	if (cmd->redirs)
	{
		ft_fork_solo_cmd(data, env, cmd_head, error);
		heredoc_tmp_deletion(cmd_head);
	}
	else
		ft_execute_solo_cmd(cmd, data, env, cmd_head);
}
