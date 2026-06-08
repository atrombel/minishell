/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:10 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:01:10 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"
#include "cgasser.h"

int	hd_ctrl_d(t_data *data, t_redir *redir)
{
	ft_signals();
	ft_putstr_fd("minishell: warning: here-document delimited by end-of-file\n"
		"(wanted `", 2);
	ft_putstr_fd(redir->arg, 2);
	ft_putstr_fd("')\n", 2);
	secure_close(&redir->hd_tmp_fd);
	redir->hd_tmp_fd = open(redir->hd_filename, O_RDONLY);
	if (redir->hd_tmp_fd < 0)
	{
		perror("minishell: heredoc");
		return (-1);
	}
	unlink(redir->hd_filename);
	data->last_exit_status = 0;
	return (0);
}

//fonctio qui cree le heredoc
int	heredoc_tmp_init(t_redir *redir, t_data *data)
{
	char	*str;
	char	*nbr;

	nbr = ft_itoa(data->last_hd_nbr);
	if (!nbr)
	{
		data->last_exit_status = errno;
		return (-1);
	}
	str = ft_strjoin("heredoc_tmp", nbr);
	free(nbr);
	if (!str)
		return (data->last_exit_status = errno, -1);
	redir->hd_tmp_fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (redir->hd_tmp_fd == -1)
		return (data->last_exit_status = errno, free(str), -1);
	redir->hd_filename = ft_strdup(str);
	if (!redir->hd_filename)
	{
		secure_close(&redir->hd_tmp_fd);
		unlink(str);
		return (data->last_exit_status = errno, free(str), -1);
	}
	data->last_hd_nbr++;
	return (free(str), 0);
}

// fonction qui rempli le heredoc
int	open_heredoc(t_redir *redir, t_data *data)
{
	int	ret;

	heredoc_tmp_init(redir, data);
	signals_heredoc();
	ret = heredoc_loop(redir, data);
	ft_signals();
	return (ret);
}

// fonction qui check si y a un herdoc
int	check_if_herdoc(t_cmd	*cmd, t_data *data)
{
	t_list	*redirs;
	t_redir	*redir;

	redirs = cmd->redirs;
	while (redirs)
	{
		redir = (t_redir *)redirs->content;
		if (redir->type == IN_DELIM)
		{
			if (open_heredoc(redir, data) == -1)
				return (-1);
		}
		redirs = redirs->next;
	}
	return (0);
}

// fonction qui parcoure cmd par cmd
// WARNING strjoin dans la creation des nom de fichier tmp heredocs
int	heredoc_check_init(t_list *cmd_head, t_data *data)
{
	t_cmd	*cmd;

	while (cmd_head)
	{
		if (g_sig == SIGINT)
		{
			g_sig = 0;
			data->last_exit_status = 1;
			return (-1);
		}
		cmd = (t_cmd *)cmd_head->content;
		if (check_if_herdoc(cmd, data) == -1)
			return (-1);
		cmd_head = cmd_head->next;
	}
	return (0);
}
