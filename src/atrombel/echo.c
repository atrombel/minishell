#include "minishell.h"

void	print_echo(char *arg, t_data *data, int mode)
{
	char	*suffixes[3];

	suffixes[0] = " ";
	suffixes[1] = "";
	suffixes[2] = "\n";
	if (printf("%s%s", arg, suffixes[mode]) == -1)
	{
			data->last_exit_status = 1;
			return ;
	}
}

// echo - display a line of text
void	ft_echo(t_cmd *cmd, t_data *data)
{
	int	i;

	i = 0;
	data->last_exit_status = 0;
	if (!cmd->args || !cmd->args[0])
	{
		if (!(cmd->flag && ft_strncmp("-n", cmd->flag[0], 3) == 0))
			write(1, "\n", 1);
		return;
	}
	while (cmd->args[i + 1])
	{
		print_echo(cmd->args[i], data, 0);
		i++;
	}
	if (cmd->flag && (ft_strncmp("-n", cmd->flag[0], 3) == 0))
		print_echo(cmd->args[i], data, 1);
	else
		print_echo(cmd->args[i], data, 2);
}
