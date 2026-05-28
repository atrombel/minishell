
#include "cgasser.h"

int	ft_is_flag(t_cmd *cmd, char *word);
int	ft_fill_flag(t_cmd *cmd, char *word);
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
	else if (ft_is_flag(cmd, word))
		status = ft_fill_flag(cmd, word);
	else
		status = ft_fill_arg(cmd, word, env);
	if (status != 0)
		return (1);
	return (0);
}

int	ft_is_flag(t_cmd *cmd, char *word)
{
	if (cmd->cmd && !cmd->flags && !cmd->args)
	{
		if (word[0] == '-' && word[1] != '\0')
			return (1);
	}
	return (0);
}

int	ft_fill_flag(t_cmd *cmd, char *word)
{
	char	*flag;

	flag = NULL;
	flag = ft_calloc(sizeof(char), ft_strlen(word) + 1);
	if (!flag)
		return (perror(ALLOC_ERR), 1);
	ft_strlcpy(flag, word, ft_strlen(word) + 1);
	ft_lstadd_back(&cmd->flags, ft_lstnew(flag));
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
	ft_lstadd_back(&cmd->args, ft_lstnew(arg));
	return (0);
}
