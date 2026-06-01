#include "minishell.h"
#include "atrombel.h"

char	*ft_readline(t_env *env)
{
	char	*user_input;
	char	*dest;
	char	*str;

	str = getcwd(NULL, 0);
	if (!str)
	{
		str = ft_get_value_env(env, "PWD");
		if (!str)
		{
				str = ft_strdup("minishell");
			if (!str)
			{
				perror("minishell: ");
				return (NULL);
			}
		}
	}
	dest = ft_strjoin("\001\033[1;32m\002", str);
	if (!dest)
	{
		perror("minishell: ");
		return (NULL);
	}
	free(str);
	str = ft_strjoin(dest, "\001\033[0m\002$ ");
	free(dest);
	if (!str)
	{
		perror("minishell: ");
		return (NULL);
	}
	user_input = readline(str);
	free (str);
	return (user_input);
}
