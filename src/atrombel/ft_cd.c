#include "minishell.h"

int	cd_success(t_env *env, char *old_pwd)
{
	char	new_wd[PATH_MAX];

	ft_change_value_env(env, "OLDPWD", old_pwd);
	free(old_pwd);
	if (getcwd(new_wd, PATH_MAX) == NULL)
	{
		perror("minishell:cd:");
		return (1);
	}
	ft_change_value_env(env, "PWD", new_wd);
	return (0);
}

// function that actually changes current working wirectory and update pwd and oldpwd fomr env
void	ft_chdir(char	*path, t_data *data, t_env *env)
{
	char	*old_pwd;

	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(path);
		data->last_exit_status = 1;
		return ;
	}
	else
	{
		old_pwd = ft_get_value_env(env,"PWD");
		if (cd_success(env, old_pwd) == 1)
			data->last_exit_status = 1;
		else
			data->last_exit_status = 0;
	}
}

//cd args change the working directory
void	ft_cd(t_cmd *content, t_data *data, t_env *env)
{
	char	*path;

	if (content->args == NULL || content->args[0] == NULL || content->args[0][0] == '\0')
	{
		path = ft_get_value_env(env,"HOME");
		ft_chdir(path, data, env);
		return ;
	}
	else
		path = content->args[0];
	if (content->args[0] && content->args[1])
	{
		data->last_exit_status = 1;

		ft_putstr_fd("minishell: cd: too many arguments", 2);
		return ;
	}
	ft_chdir(path, data, env);
}

