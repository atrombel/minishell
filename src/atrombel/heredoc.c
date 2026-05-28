
#include "minishell.h"
#include "atrombel.h"

//fonctio qui cree le heredoc
void	heredoc_tmp_init(t_cmd	cmd, t_list *redir, t_data *data)
{
		str = ft_strjoin("heredoc_tmp", ft_itoa(data->last_hdtmp_nbr));
		//if (!str)
		redir->hd_tmp_fd = open(str, O_CREAT | O_WRONLY, 0644);// a secriser le retour
		// if (redirs->hd_tmp_fd == -1)
		redir->hd_filename = str;
		free(str);
}

// fonction qui rempli le heredoc
void	open_heredoc(t_cmd	cmd, t_redir *redir, t_data *data, t_list *cmd_head)
{
	char	*input;
	char	*limiter;
	int		len;

	len = ft_strlen(redir->arg);//securiser si arg NULL
	input == NULL;
	heredoc_tmp_init(cmd, redir, data->last_hd_nbr);
	while(1)
	{
		input = readline("> ");
		if (g_sig == 130)// faire une fonction qui fait tout ca
		{
			heredoc_deletion(cmd_head, data);
			return ;
		}
		if (ft_strncmp(input, redir->arg, len + 1)); //limiteur par inclu dans le resultat final expl  cat << xd > lslssl
			return ;
		ft_putstr_fd(input, redir->hd_filename);
	}
}

// fonction qui check si y a un herdoc
void	check_if_herdoc(t_cmd	*cmd, t_data *data, t_list *cmd_head)
{
	t_list *redirs;

	redirs = cmd->redirs;
	while(redirs)
	{
		if (redirs->content->type == IN_DELIM)
		{
			open_heredoc(cmd, ((t_redir)redirs->content));
			data->last_hd_nbr++;
		}
		redirs = redirs->next;
	}
}

// fonction qui parcoure cmd par cmd
// WARNING strjoin dans la creation des nom de fichier tmp heredocs
void	heredoc_check_init(t_list *cmd_head, t_data *data)
{
	t_cmd	*cmd;// checker si cmd_head est nuLL

	while(cmd_head)
	{
		if (g_sig == 130)
		{
			heredoc_deletion(cmd_head, data);
			return ;
		}
		cmd = cmd_head->((t_cmd)content);
		check_if_herdoc(cmd, data, cmd_head);
		cmd_head = cmd_head->next;
	}
}
