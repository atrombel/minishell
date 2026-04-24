
#include "minishell.h"
#include "cgasser.h"
#include <stdlib.h>

int	ft_cmd_cmp_envp(t_token *token, char **paths) 
{
	int	i;
	char	*cmd_path;
	char	*word;
	int	size;

	i = 0;
	size = 0;
	cmd_path = NULL;
	word = token->word;
	if (!paths)
		return (1);
	while (paths[i] != NULL)
	{
		size = ft_strlen(word) + ft_strlen(paths[i]) + 2;
		cmd_path = malloc(size);
		ft_strlcpy(cmd_path, paths[i], ft_strlen(paths[i]) + 1);
		ft_strlcat(cmd_path, "/", ft_strlen(paths[i]) + 2);
		ft_strlcat(cmd_path, word, size);
		if (access(cmd_path, X_OK) == 0)
			return (ft_free_array(paths), free(cmd_path), 0);
		free(cmd_path);
		i++;
	}
	ft_free_array(paths);
	return (1);
}
