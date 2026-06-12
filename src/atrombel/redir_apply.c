/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:18 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:01:18 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

// Applies all redirections associated with a command node that
// if error = 0 all good else ...
int	ft_redir_apply(t_list *cmd_head, t_data *data)
{
	t_list	*redirs;
	t_redir	*redir;
	int		error;

	error = 0;
	if (!((t_cmd *)cmd_head->content)->redirs)
		return (error);
	redirs = ((t_cmd *)cmd_head->content)->redirs;
	while (redirs)
	{
		redir = (t_redir *)redirs->content;
		if (redir->type == IN)
			stdin_redir(redir, data, &error);
		else if (redir->type == OUT)
			stdout_redir(redir, data, &error);
		else if (redir->type == HEREDOC)
			heredoc_reddir_apply(redir, data, &error);
		else if (redir->type == APPEND)
			stdout_appnd(redir, data, &error);
		if (error == 1)
			break ;
		redirs = redirs->next;
	}
	return (error);
}

// restores the original
//standard input and output file descrptors
// after redirection execution,
// and cleans up all temporary file descriptors.
// This function is used to reset the shell state after executing a command
// that modified stdin/stdout (via dup2 redirections)
void	fd_redir_restoration_close(t_data *data)
{
	if (data->stdin_save >= 0)
	{
		if (dup2(data->stdin_save, 0) == -1)
			error_print("error");
		secure_close(&data->stdin_save);
	}
	if (data->stdout_save >= 0)
	{
		if (dup2(data->stdout_save, 1) == -1)
			error_print("error");
		secure_close(&data->stdout_save);
	}
	if (data->infile != -1)
		secure_close(&data->infile);
	if (data->outfile != -1)
		secure_close(&data->outfile);
}
