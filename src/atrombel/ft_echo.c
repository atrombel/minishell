#include "minishell.h"
#include "atrombel.h"

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

// data last command error number "echo $?"" to implement also echo should display env  ? if yes to implement as well expl echo $PWD/home/atrombel/42/3/minishell
// echo - display a line of text
void	ft_echo(t_cmd *cmd, t_data *data)
{
	int	i;

	i = 0;
	data->last_exit_status = 0;
	if (!cmd->args || !((char *)cmd->args->content)[0])
	{
		if (!(cmd->flags && ft_strncmp("-n", ((char *)cmd->flags->content), 3) == 0))// et si on a un turc comme echo -en BEN ECHO CAPTE LES 2 FLAG MAIS SURTOUT LE N DONC FT_STRNCMP NE MARCHERA
			write(1, "\n", 1);
		return;
	}
	while (((char *)cmd->args->content)[i + 1])
	{
		print_echo(((char *)cmd->args->content), data, 0);
		i++;
	}
	if (cmd->flags && (ft_strncmp("-n",  ((char *)cmd->flags->content), 3) == 0))
		print_echo(((char *)cmd->args->content), data, 1);
	else
		print_echo(((char *)cmd->args->content), data, 2);
}
