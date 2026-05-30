
#include "cgasser.h"

#include "ft_printf.h"

int	ft_fill_arg(t_cmd *cmd, char *word, t_env *env);

int	ft_fill_word(t_cmd *cmd, char *word, t_env *env)
{
	int	status;

	status = 0;
	if (!cmd->cmd && !cmd->path)
	{
		if(ft_fill_cmd(cmd, word, env) != 0)
			return (1);
	}
	else
		status = ft_fill_arg(cmd, word, env);
	if (status != 0)
		return (1);
	return (0);
}


int	ft_fill_arg(t_cmd *cmd, char *word, t_env *env)
{
	char	*arg;

	arg = NULL;
	arg = ft_calloc(sizeof(char), ft_strlen(word) + 1);
	if (!arg)
		return (perror(ALLOC_ERR), 1);
	ft_strlcpy(arg, word, ft_strlen(word) + 1);
	arg = ft_expand_var(arg, env);
	arg = ft_trim_quotes(arg);
	cmd->args = ft_arrayadd_back(cmd->args, arg);
	return (0);
}
