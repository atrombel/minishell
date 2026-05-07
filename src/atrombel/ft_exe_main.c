#include "minishell.h"

//function that will check if the function is a builtin, retour code erreur a reflechir
int ft_builtin_verif(t_cmd *content, t_data *data, t_env *env, t_list *head)
{

	if (ft_strncmp("echo", content->cmd, 5) == 0)
		ft_echo(content, data);
	if (ft_strncmp("cd", content->cmd, 3) == 0)
		ft_cd(content, data, env);
	if (ft_strncmp("pwd", content->cmd, 4) == 0)
		ft_pwd(data, env);
	if (ft_strncmp("env", content->cmd, 4) == 0)
		ft_env(data, env);
	if (ft_strncmp("exit", content->cmd, 4) == 0)
		ft_exit(content, env, head);
	return (0);
}

// main function that will sort and  organise the operation between the execution processes
int	ft_exe_main(t_list *head, t_data *data, t_env *env)
{
	if (head)
	{
		if (ft_builtin_verif((t_cmd *)head->content, data, env, head) == -1)
			return (-1);
	}
	return (0);
}
