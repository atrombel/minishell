
#include "minishell.h"
#include "atrombel.h"



// update "-=..." in env, use ONLY if cmd execution was succesful
void	env_lst_cmd_update(t_env *env, t_cmd *cmd)
{
	char	*new_key;

	new_key = NULL;
	if (ft_get_value_env(env, "_") == NULL)
	{
		new_key = ft_strjoin("_=", cmd_path);// malloc to secure
		if (!new_key)
			return ;
		ft_addnew_key_and_value(env, new_key);
	}
	else
		ft_change_value_env(env, "_", cmd_path);
}
