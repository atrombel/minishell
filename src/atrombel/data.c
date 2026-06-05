/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:51:20 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 15:51:20 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"
#include "atrombel.h"

void	data_init(t_data	*data, t_env	*envp)
{
	data->last_exit_status = 0;
	data->infile = -1;
	data->outfile = -1;
	data->stdin_save = -1;
	data->stdout_save = -1;
	data->tmp_fd = -1;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
	data->last_hd_nbr = 0;
	data->env = envp;
}
