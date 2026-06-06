/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:51:47 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 15:51:47 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "atrombel.h"

//pipe_fd[0] = fd de lecture
//pipe_fd[1] = fd d'écriture


void	cmd_pipe_exe(t_list *cmd_head, t_data *data, t_env **env)
{
	t_cmd *cmd;

	if (!cmd_head || !cmd_head->content)
		return ;
	cmd = (t_cmd *)cmd_head->content;
	if (redir_but_cmd_invalid(cmd_head, data, cmd) == 1)
		return ;
	if (ft_builtin_verif(cmd_head->content) == 1)
	{
		solo_builtin(cmd_head, data, env);
		exit(data->last_exit_status);// checker des erreur avec ca
	}
	else
	{
		set_signals_default();
		ft_execute_cmd(cmd, env);
	}
	exit(0);
}

void	reset_pipe(t_data *data, int mode)
{
	if (mode == 1)
	{
		close(data->pipe_fd[0]);
		data->pipe_fd[0] = -1;
	}
	close(data->pipe_fd[1]);
	data->pipe_fd[1] = -1;
}

void	child_exe(t_list *cmd_head, t_data *data, t_env **env)
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
	if (ft_redir_apply(cmd_head, data) != 0)
		exit(1);
	cmd_pipe_exe(cmd_head, data, env);
}
void	exe_pipeline(t_list *cmd_head, t_data *data, pid_t pid, t_env **env)
{

	if (cmd_head->next)
		pipe(data->pipe_fd);
	set_signals_ignore();
	pid = fork();
	if (pid == -1)
	{
		error_print("exe_pipe");
		return ;
	}
	if (pid == 0) // faire aussi cas < 0
		child_exe(cmd_head, data, env);
	data->tmp_fd = data->pipe_fd[0];
	if (cmd_head->next)
		reset_pipe(data, 0);
	else
		reset_pipe(data, 1);

}
