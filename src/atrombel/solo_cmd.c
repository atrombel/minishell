
#include "minishell.h"
#include "atrombel.h"

void	solo_cmd(t_list *cmd_head, t_data *data, t_env **env)
{
	t_cmd *cmd;

	if (!cmd_head || !cmd_head->content)
		return ;
	cmd = (t_cmd *)cmd_head->content;
	if (!cmd->args || !cmd->args[0])
	{
		if (cmd->redirs)
		{
			data->stdin_save = dup(0);
			data->stdout_save = dup(1);
			ft_redir_apply(cmd_head, data);
			fd_redir_restoration_close(data);
			heredoc_tmp_deletion(cmd_head, data);
		}
		return ;
	}
	if (ft_builtin_verif((t_cmd *)cmd_head->content) == 1)
		solo_builtin(cmd_head, data, env);
	else
		solo_cmd_not_builtin(cmd_head, data, env);
}
