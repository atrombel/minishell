/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:37 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:01:37 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "atrombel.h"

// update "-=..." in env
void	env_lst_cmd_update(t_env *env, char *last_arg, t_data *data)
{
	char	*new_key;

	new_key = NULL;
	if (ft_get_value_env(env, "_") == NULL)
	{
		new_key = ft_strjoin("_=", last_arg);
		if (!new_key)
		{
			data->last_exit_status = 1;
			return ;
		}
		if (ft_addnew_key_and_value(env, new_key) == 1)
		{
			data->last_exit_status = 1;
			return ;
		}
	}
	else
		ft_change_value_env(env, "_", last_arg);
}


void	update_underscore_env( t_env **env, t_cmd *cmd, t_data *data)
{
	int	i;

	i = 0;
	if (!cmd->args || !cmd->args[0])
		return ;
	while (cmd->args[i])
		i++;
	i--;
	env_lst_cmd_update(*env, cmd->args[i], data);
}

int	redir_but_cmd_invalid(t_list *cmd_head, t_data *data, t_cmd *cmd)
{
	if (!cmd->is_valid)
	{
		if (cmd->redirs)
		{
			data->stdin_save = dup(0);
			data->stdout_save = dup(1);
			ft_redir_apply(cmd_head, data);// securiser
			fd_redir_restoration_close(data);
		}
		if (cmd->args && cmd->args[0])
		{
			command_not_found(cmd->args[0]);
			data->last_exit_status = 127;
		}
		return 1;
	}
	return (0);
}

void	solo_cmd(t_list *cmd_head, t_data *data, t_env **env)
{
	t_cmd *cmd;

	if (!cmd_head || !cmd_head->content)
		return ;
	cmd = (t_cmd *)cmd_head->content;
	// if (!cmd->is_valid)
	// {
	// 	if (cmd->redirs)
	// 	{
	// 		data->stdin_save = dup(0);
	// 		data->stdout_save = dup(1);
	// 		ft_redir_apply(cmd_head, data);
	// 		fd_redir_restoration_close(data);
	// 		heredoc_tmp_deletion(cmd_head, data);
	// 	}
	// 	if (cmd->args && cmd->args[0])
	// 	{
	// 		command_not_found(cmd->args[0]);
	// 		data->last_exit_status = 127;
	// 	}
	// 	return ;
	// }
	if (redir_but_cmd_invalid(cmd_head, data, cmd) == 1)
		return ;
	if (ft_builtin_verif((t_cmd *)cmd_head->content) == 1)
		solo_builtin(cmd_head, data, env);
	else
		solo_cmd_not_builtin(cmd_head, data, env);
	update_underscore_env(env, cmd, data);
}
