
#include "cgasser.h"
#include "ft_printf.h"

int	ft_check_cmd(t_cmd *cmd, char *word, t_env *env);
int	ft_check_env(t_cmd *cmd, char *word, char **paths);
char	**ft_get_envpaths(t_env *env);
int	ft_is_word_path(t_cmd *cmd, char *word);

int	ft_fill_cmd(t_cmd *cmd, char *word, t_env *env)
{
	if (ft_check_cmd(cmd, word, env) == 0)
	{
		cmd->cmd = ft_calloc(sizeof(char *), (ft_strlen(word) + 1));
		if (!cmd->cmd)
			return (perror(ALLOC_ERR), 1);
		ft_strlcpy(cmd->cmd, word, ft_strlen(word) + 1);
		return (0);
	}
	if (ft_is_word_path(cmd, word) == 1)
		return (0);
	ft_printr("Error\nUnvalid command: %s\n", word);
	return (1);
}

int	ft_check_cmd(t_cmd *cmd, char *word, t_env *env)
{
	if (ft_strncmp(word, "echo", 5) == 0)
		return (0);
	else if (ft_strncmp(word, "cd", 3) == 0)
		return (0);
	else if (ft_strncmp(word, "pwd", 4) == 0)
		return (0);
	else if (ft_strncmp(word, "export", 7) == 0)
		return (0);
	else if (ft_strncmp(word, "unset", 6) == 0)
		return (0);
	else if (ft_strncmp(word, "env", 4) == 0)
		return (0);
	else if (ft_strncmp(word, "exit", 5) == 0)
		return (0);
	else if (ft_check_env(cmd, word, ft_get_envpaths(env)) == 0)
		return (0);
	return (1);
}

int	ft_check_env(t_cmd *cmd, char *word, char **paths) 
{
	int	i;
	char	*cmd_path;
	int	size;

	i = 0;
	size = 0;
	cmd_path = NULL;
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
			return (ft_free_array(paths), cmd->path = cmd_path, 0);
		free(cmd_path);
		i++;
	}
	ft_free_array(paths);
	return (1);
}

char	**ft_get_envpaths(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp != NULL)
	{
		if (ft_strncmp("PATH", temp->key, 5) == 0)
			return (ft_split(temp->value, ':'));
		temp = temp->next;
	}
	return (NULL);
}

int	ft_is_word_path(t_cmd *cmd, char *word)
{
	char	*path;

	path = NULL;
	if (access(word, X_OK) == 0)
	{
		path = ft_calloc(sizeof(char), ft_strlen(word) + 1);
		ft_strlcpy(path, word, ft_strlen(word) + 1);
		cmd->path = path;
		return (1);
	}
	return (0);
}
