/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_cmd_not_builtin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:34 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:01:34 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"
#include "cgasser.h"

void	waitpid_operations(t_data *data)
{
	int	status;
	int	last_status;

	last_status = 0;
	while (waitpid(-1, &status, 0) > 0)
		last_status = status;
	if (WIFEXITED(last_status))
		data->last_exit_status = WEXITSTATUS(last_status);
	else if (WIFSIGNALED(last_status))
	{
		if (WTERMSIG(last_status) == SIGINT)
			write(1, "\n", 1);
		else if (WTERMSIG(last_status) == SIGQUIT)
			write(1, "Quit (core dumped)\n", 19);
		data->last_exit_status = 128 + WTERMSIG(last_status);
	}
}

void	ft_execute_cmd(t_cmd *cmd, t_env **env)
{
	char	**envp;

	is_minishell_lvl(cmd, env);
	envp = env_to_charstar_reconversion(*env);
	if (!envp)
	{
		error_print("ERROR");
		exit(1);
	}
	set_signals_default();
	execve(cmd->path, cmd->args, envp);
	charstar_env_clean(envp);
	error_print("execve failed");
	if (errno == EACCES)
		exit(126);
	exit(127);
}

// organise execution of cmd and application of redir
void	ft_execute_cmd_redir(t_cmd	*cmd, t_data *data,
	t_env **env, t_list *cmd_head)
{
	int	pid;

	set_signals_ignore();
	pid = fork();
	if (pid == -1)
	{
		error_print("fork");
		return ;
	}
	else if (pid == 0)
	{
		if (cmd->redirs && ft_redir_apply(cmd_head, data) != 0)
			exit(1);
		ft_execute_cmd(cmd, env);
		exit(127);
	}
	else if (pid > 0)
		waitpid_operations(data);
}

void	solo_cmd_not_builtin(t_list *cmd_head, t_data *data, t_env **env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)cmd_head->content;
	ft_execute_cmd_redir(cmd, data, env, cmd_head);
}
