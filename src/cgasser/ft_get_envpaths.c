

#include "minishell.h"
#include "cgasser.h"

char	**ft_get_envpaths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (ft_split(envp[i], ':'));
		i++;
	}
	return (NULL);
}
