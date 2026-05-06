// #include "minishell.h"

// //cd args change the working directory
// void	ft_cd(t_cmd *cmd)
// {
// 	char	*path;
// 	char	*old_pwd;

// 	if (cmd->args[0] && cmd->args[1])
// 		return (1);
// 	path = cmd->args[0];
// 	old_pwd = getenv("PWD");
// 	if (!path)
// 		path = getenv("HOME"); // pas check si env existe
// 	if (chdir(path) == -1)
// 	{
// 		ft_putstr_fd("minishell: cd: ", 2);
// 		perror(path);
// 		return (1)
// 	}
// 	return (0);
// }

