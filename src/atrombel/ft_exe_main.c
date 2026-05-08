#include "minishell.h"

//function that will check if the function is a builtin, retour code erreur a reflechir
//function return 0 if builtin else 1
int ft_builtin_verif(t_cmd *content, t_data *data, t_env *env, t_list *head)
{

	if (ft_strncmp("echo", content->cmd, 5) == 0)
		return (ft_echo(content, data), 0);
	if (ft_strncmp("cd", content->cmd, 3) == 0)
		return (ft_cd(content, data, env), 0);
	if (ft_strncmp("pwd", content->cmd, 4) == 0)
		return (ft_pwd(data, env), 0);
	if (ft_strncmp("env", content->cmd, 4) == 0)
		return (ft_env(data, env), 0);
	if (ft_strncmp("exit", content->cmd, 4) == 0)
		return (ft_exit(content, env, head), 0);
	if (ft_strncmp("export", content->cmd, 4) == 0)
		return (ft_export(content, env), 0);
	return (1);
}

// main function that will sort and  organise the operation between the execution processes
int	ft_exe_main(t_list *head, t_data *data, t_env *env)
{
	if (head)
	{
		if (ft_builtin_verif((t_cmd *)head->content, data, env, head) == 1)
			return (-1);
	}
	return (0);

}
