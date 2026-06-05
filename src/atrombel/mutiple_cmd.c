/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutiple_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:17 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:01:17 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"
#include "atrombel.h"

void	multiple_cmd(t_list *cmd_head, t_data *data, t_env **env)
{
	pid_t pid;

	pid = -1;
	while (cmd_head)
	{
		if (cmd_head->content)
			exe_pipeline(cmd_head, data, pid, env);
		cmd_head = cmd_head->next;
	}
	waitpid_operations(data);
}
