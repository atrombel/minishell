#include "minishell.h"
#include "atrombel.h"

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
	(void)data;// AAAAAAAAAA ENLEVER
	int	i;
	int	boul;

	boul = 0;
	i = 1;
	if (!cmd->args || !cmd->args[0] || !cmd->args[1])
	{
		write(1,"\n", 1);
		return;
	}
	while (is_valid_n_flag(cmd->args[i]) == 1)
	{
		boul = 1;
		i++;
	}
	while (cmd->args[i])
	{

		write(1, cmd->args[i], ft_strlen(cmd->args[i]));
		i++;
		if (cmd->args[i] && cmd->args[i][0] != '\0')
			write(1," ", 1);
	}
	if (boul == 0)
		write(1,"\n", 1);

}
