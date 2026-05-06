#include "minishell.h"

// echo - display a line of text
void	ft_echo(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i + 1])
	{
		printf("%s ", cmd->args[i]);
		i++;
	}
	if (cmd->flag && (ft_strncmp("-n", cmd->flag[0], 3) == 0))
		printf("%s", cmd->args[i]);
	else
		printf("%s\n", cmd->args[i]);
}
