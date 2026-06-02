#include "minishell.h"
#include "atrombel.h"

//function that will check if the function is a builtin, retour code erreur a reflechir
//function return 0 if builtin else 1
// faut lui passer cmd par cmd cmd_head->content
int ft_builtin_verif(t_cmd *cmd)
{
	if (!cmd || !cmd->args || !cmd->args[0])
		return (0);
	if (ft_strncmp("echo", cmd->args[0], 5) == 0)
		return (1);
	if (ft_strncmp("cd", cmd->args[0], 3) == 0)
		return (1);
	if (ft_strncmp("pwd", cmd->args[0], 4) == 0)
		return (1);
	if (ft_strncmp("env", cmd->args[0], 4) == 0)
		return (1);
	if (ft_strncmp("exit", cmd->args[0], 5) == 0)
		return (1);
	if (ft_strncmp("export", cmd->args[0], 7) == 0)
		return (1);
	if (ft_strncmp("unset", cmd->args[0], 6) == 0)
		return (1);
	return (0);
}

int	ft_execute_builtin(t_cmd *cmd, t_data *data, t_env **env, t_list *head)
{
	if (!cmd || !cmd->args[0])
		return (0);
	if (ft_strncmp("echo", cmd->args[0], 5) == 0)
		return (ft_echo(cmd, data), 0);
	if (ft_strncmp("cd", cmd->args[0], 3) == 0)
		return (ft_cd(cmd, data, *env), 0);
	if (ft_strncmp("pwd", cmd->args[0], 4) == 0)
		return (ft_pwd(data, *env), 0);
	if (ft_strncmp("env", cmd->args[0], 4) == 0)
		return (ft_env(data, *env), 0);
	if (ft_strncmp("exit", cmd->args[0], 5) == 0)
		return (ft_exit(cmd, *env, head, data), 0);
	if (ft_strncmp("export", cmd->args[0], 7) == 0)
		return (ft_export(cmd, *env), 0);
	if (ft_strncmp("unset", cmd->args[0], 6) == 0)
		return (ft_unset(cmd, env), 0);
	return (1);
}
