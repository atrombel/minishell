#include "minishell.h"

//function that will check if the function is a builtin, retour code erreur a reflechir
void ft_builtin_verif(t_cmd *content, t_data *data, t_env *env)
{
	if (ft_strncmp("echo", content->cmd, 5) == 0)
		ft_echo(content, data);
	if (ft_strncmp("cd", content->cmd, 3) == 0)
		ft_cd(content, data, env);
	if (ft_strncmp("pwd", content->cmd, 4) == 0)
		ft_pwd(data, env);


}

// main function that will sort and  organise the operation between the execution processes
void	ft_exe_main(t_list *head, t_data *data, t_env *env)
{
	//printf("head->content->cmd = %s\n", ((t_cmd *)head->content)->cmd);
	(void)env;
	if (head)
		ft_builtin_verif((t_cmd *)head->content, data, env);

}
