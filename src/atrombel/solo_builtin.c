/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:28 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:01:28 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "atrombel.h"

//Executes a builtin command when it is not part of a pipeline
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
		fd_redir_restoration_close(data);
		//heredoc_tmp_deletion(cmd_head, data);
	}
	else
		ft_execute_builtin(cmd, data, env, cmd_head);
}
