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

void	hd_ctrl_d(t_data *data, t_redir *redir)
{
	ft_putstr_fd("minishell: warning: here-document delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(redir->arg, 2);
	ft_putstr_fd("')\n", 2);
	close(redir->hd_tmp_fd);
	redir->hd_tmp_fd = open(redir->hd_filename, O_RDONLY);
	if (redir->hd_tmp_fd < 0)
		perror("minishell: heredoc");
	unlink(redir->hd_filename); //
	data->last_exit_status = 0;
}

//fonctio qui cree le heredoc
void	heredoc_tmp_init(t_redir *redir, t_data *data)
{
	char *str;
	char *nbr;

	nbr = ft_itoa(data->last_hd_nbr);
	str = ft_strjoin("heredoc_tmp", nbr);
	free(nbr);
	printf("hd = %s\n", str);
	if (!str)
	{
		data->last_exit_status = errno;// verifier
		return ; // a voir comment le securiser mieux que ca a la fin
	}
	redir->hd_tmp_fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);// a secriser le retour
	if (redir->hd_tmp_fd == -1)// a definir
		data->last_exit_status = errno;
	redir->hd_filename = ft_strdup(str);
	data->last_hd_nbr++;
	free(str);

}

// fonction qui rempli le heredoc
void	open_heredoc(t_redir *redir, t_data *data, t_list *cmd_head)
{
	(void)cmd_head;
	char	*input;
	int	 len;

	len = ft_strlen(redir->arg);
	heredoc_tmp_init(redir, data);
	while (1)
	{
		input = readline("> ");
		if (g_sig == 130)
		{
			free(input);
			//heredoc_tmp_deletion(cmd_head, data);
			return ;
		}
		if (!input)
		{
			hd_ctrl_d(data, redir);
			break ;
		}
		if (ft_strncmp(input, redir->arg, len + 1) == 0)
		{
			free(input);
			close(redir->hd_tmp_fd);
			redir->hd_tmp_fd = open(redir->hd_filename, O_RDONLY);
			if (redir->hd_tmp_fd < 0)
				perror("minishell: heredoc");
			unlink(redir->hd_filename);
			break ;
		}
		input = ft_expand_var(input, data);
		ft_putstr_fd(input, redir->hd_tmp_fd);
		ft_putstr_fd("\n", redir->hd_tmp_fd);
		free(input);
	}
}

// fonction qui check si y a un herdoc
void	check_if_herdoc(t_cmd	*cmd, t_data *data, t_list *cmd_head)
{
	t_list *redirs;
	t_redir *redir;

	redirs = cmd->redirs;
	while(redirs)
	{
		redir = (t_redir *)redirs->content;
		if (redir->type == IN_DELIM)
			open_heredoc(redir, data, cmd_head);
		redirs = redirs->next;
	}
}

// fonction qui parcoure cmd par cmd
// WARNING strjoin dans la creation des nom de fichier tmp heredocs
void	heredoc_check_init(t_list *cmd_head, t_data *data)
{
	t_cmd	*cmd;

	while(cmd_head)
	{
		if (g_sig == 130)
		{
			//heredoc_tmp_deletion(cmd_head, data);
			return ;
		}
		cmd = (t_cmd *)cmd_head->content;
		check_if_herdoc(cmd, data, cmd_head);
		cmd_head = cmd_head->next;
	}
}
