
#include "cgasser.h"

#include "ft_printf.h"

int	ft_fill_arg(t_cmd *cmd, char *word, t_data *data);

int	ft_fill_word(t_cmd *cmd, char *word, t_data *data)
{
	int	status;

	status = 0;
	if (!cmd->args && !cmd->path)
	{
		if(ft_fill_cmd(cmd, word, data->env) != 0)
			return (1);
	}
	else
		status = ft_fill_arg(cmd, word, data);
	if (status != 0)
		return (1);
	return (0);
}


int	ft_fill_arg(t_cmd *cmd, char *word, t_data *data)
{
	char	*arg;

	arg = NULL;
	arg = ft_calloc(sizeof(char), ft_strlen(word) + 1);
	if (!arg)
		return (1);
	ft_strlcpy(arg, word, ft_strlen(word) + 1);
	arg = ft_expand_var(arg, data);
	if (!arg)
		return (1);
	arg = ft_trim_quotes(arg);
	if (!arg)
		return (1);
	cmd->args = ft_arrayadd_back(cmd->args, arg);
	return (0);
}
