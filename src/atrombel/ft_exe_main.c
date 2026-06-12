/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:52:24 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/12 11:38:35 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

// main function that will sort and
// organise the operation between the execution processes
void	ft_exe_main(t_list *cmd_head, t_data *data, t_env **env)
{
	if (!cmd_head || !cmd_head->content)
		return ;
	if (heredoc_check_init(cmd_head, data) == -1)
		return ;
	if (cmd_head->next)
		multiple_cmd(cmd_head, data, env);
	else
		solo_cmd(cmd_head, data, env);
}
