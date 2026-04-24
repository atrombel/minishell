
#include "minishell.h"
#include "cgasser.h"
#include "ft_printf.h"

int	ft_cmd_cmp_envp(t_token *token, char **envp);

int	ft_cmd_cmp(t_token *token, char **envp)
{
	(void)envp;
	if (ft_strncmp(token->word, "echo", 5) == 0)
		return (0);
	else if (ft_strncmp(token->word, "cd", 3) == 0)
		return (0);
	else if (ft_strncmp(token->word, "pwd", 4) == 0)
		return (0);
	else if (ft_strncmp(token->word, "export", 7) == 0)
		return (0);
	else if (ft_strncmp(token->word, "unset", 6) == 0)
		return (0);
	else if (ft_strncmp(token->word, "env", 4) == 0)
		return (0);
	else if (ft_strncmp(token->word, "exit", 5) == 0)
		return (0);
//	else if (ft_cmd_cmp_envp(token, envp) == 0)
//		return (0);
	return (1);
}

int	ft_cmd_cmp_envp(t_token *token, char **envp) 
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_printf("%s\n", envp[i]);
		if (ft_strncmp(token->word, envp[i], ft_strlen(envp[i]) + 1) == 0)
			return (0);
		i++;
	}
	return (1);
}

