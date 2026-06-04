
#include "minishell.h"
#include "atrombel.h"

// main function that will sort and  organise the operation between the execution processes
void	ft_exe_main(t_list *cmd_head, t_data *data, t_env **env)
{
	if ( !cmd_head || !cmd_head->content)
		return ;
	heredoc_check_init(cmd_head, data);
	if(cmd_head->next)
		multiple_cmd(cmd_head, data, env);
	else
		solo_cmd(cmd_head, data, env);
}
