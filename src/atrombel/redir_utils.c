/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:21 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:01:21 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

//apply redirection "<" expl cat < po.c
void	stdin_redir(t_redir *redir, t_data *data, int *error)
{
	data->infile = open(redir->arg, O_RDONLY);
	if (data->infile < 0)
	{
		// if (redir->is_ambigous == 1)
		// 	error_msg("", "ambiguous redirect");
		// else
			error_print(redir->arg);
		data->last_exit_status = 1;
		*error = 1;
		return ;
	}
	if (dup2(data->infile, 0) == -1)
	{
		perror("dup2");
		*error = 1;
	}
	secure_close(&data->infile);
}

//apply redirection ">" expl cat > po.c
void	stdout_redir(t_redir *redir, t_data *data, int *error)
{
	data->outfile = open(redir->arg, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfile < 0)
	{
		error_print(redir->arg);
		data->last_exit_status = 1;
		*error = 1;
		return ;
	}
	if (dup2(data->outfile, 1) == -1)
	{
		perror("dup2");
		*error = 1;
	}
	secure_close(&data->outfile);
}

//apply redirection ">>"
void	stdout_appnd(t_redir *redir, t_data *data, int *error)
{
	data->outfile = open(redir->arg, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (data->outfile < 0)
	{
		error_print(redir->arg);
		data->last_exit_status = 1;
		*error = 1;
		return ;
	}
	if (dup2(data->outfile, 1) == -1)
	{
		perror("dup2");
		*error = 1;
	}
	secure_close(&data->outfile);
}

//apply redirection "<<"
void	heredoc_reddir_apply(t_redir *redir, t_data *data, int *error)
{
	if (redir->hd_tmp_fd == -1)
	{
		data->last_exit_status = 1;
		*error = 1;
		return ;
	}
	if (dup2(redir->hd_tmp_fd, 0) == -1)
	{
		perror("dup2");
		*error = 1;
	}
	secure_close(&redir->hd_tmp_fd);
	redir->hd_tmp_fd = -1;
}
