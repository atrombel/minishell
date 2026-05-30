#include "minishell.h"
#include "atrombel.h"

void	print_echo(char *arg, t_data *data)
{
	if (printf("%s", arg) == -1)
	{
			data->last_exit_status = 1;
			return ;
	}
}

// return 1 if arg[0] is a valid -n flag
int	is_valid_n_flag(char *args)
{
	int	i;

	if (!args)
		return (0);
	if (args[0] != '-' || args[1] != 'n')
		return (0);
	i = 2;
	while (args[i])
	{
		if (args[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

// data last command error number "echo $?"" to implement also echo should display env ? if yes to implement as well expl echo $PWD/home/atrombel/42/3/minishell
// echo - display a line of text
void	ft_echo(t_cmd *cmd, t_data *data)
{
	data->last_exit_status = 0;
	int	i;

	i = 0;
	if (!cmd->args || !(cmd->args[0]))
	{

		if (is_valid_n_flag(cmd->args[0]) == 0)
			write(1,"\n", 1);
		data->last_exit_status = 1;
		return;
	}
	while (cmd->args[i])
	{
		print_echo(cmd->args[i], data);
		i++;
	}
	if (is_valid_n_flag(cmd->args[0]) == 0)
		write(1,"\n", 1);
}
