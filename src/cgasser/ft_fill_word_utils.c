
#include "minishell.h"
#include "cgasser.h"
#include "ft_printf.h"

int	ft_check_cmd(t_cmd *cmd, char *word, char **envp);
int	ft_check_env(t_cmd *cmd, char *word, char **paths);
char	**ft_get_envpaths(char **envp);

int	ft_fill_cmd(t_cmd *cmd, char *word, char **envp)
{
	if (ft_check_cmd(cmd, word, envp) == 0)
	{
		cmd->cmd = ft_calloc(sizeof(char *), (ft_strlen(word) + 1));
		if (!cmd->cmd)
			return (perror(ALLOC_ERR), 1);
		ft_strlcpy(cmd->cmd, word, ft_strlen(word) + 1);
		return (0);
	}
	ft_printr(WRG_CMD, word);
	return (1);
}

int	ft_check_cmd(t_cmd *cmd, char *word, char **envp)
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
	else if (ft_check_env(cmd, word, ft_get_envpaths(envp)) == 0)
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

char	**ft_get_envpaths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}
