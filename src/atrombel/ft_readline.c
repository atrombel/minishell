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
	dest = ft_strjoin(str, "$ ");
	if (!dest)
	{
		perror("minishell: ");
		return (NULL);
	}
	user_input = readline(dest);
	free (dest);
	free (str);
	return (user_input);
}
