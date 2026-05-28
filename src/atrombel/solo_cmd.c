
#include "minishell.h"
#include "atrombel.h"


void	solo_cmd_not_builtin();
{





}



void	solo_cmd(t_list *cmd_head, t_data *data, t_env **env)
{
	if (ft_builtin_verif((t_cmd *)cmd_head->content) == 0)// is builting if 0
		solo_builtin(cmd_head, data, env);
	else
		solo_cmd_not_builtin(cmd_head, data, env);
}
