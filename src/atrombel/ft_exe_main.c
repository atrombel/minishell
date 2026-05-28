
#include "minishell.h"
#include "atrombel.h"

void	multiple_cmd(t_list *cmd_head, t_data *data, t_env **env)
{
	while(cmd_head)
	{




		cmd_head = cmd_head->next;
	}
}


void	solo_cmd(t_list *cmd_head, t_data *data, t_env **env)
{
	if (ft_builtin_verif((t_cmd *)cmd_head->content) == 0)// is builting if 0
	{
		if (redir_check)
		{
			ft_redir_apply(t_list *cmd_head);
			ft_execute_builtin((t_cmd *)cmd_head->content, data, env, head);
			fd_table_restoration(t_list *cmd_head);
		}
		else
			ft_execute_builtin((t_cmd *)cmd_head->content, data, env, head);
	}
	else
		solo_cmd_not_builtin()
}

// main function that will sort and  organise the operation between the execution processes
void	ft_exe_main(t_list *cmd_head, t_data *data, t_env **env)
{
	heredoc_check_init(cmd_head, data);
	if(cmd_head->next)
		multiple_cmd(cmd_head, data, env);
	else
		solo_cmd(cmd_head, data, env);
}
