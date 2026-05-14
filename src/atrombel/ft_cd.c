#include "minishell.h"
#include "atrombel.h"

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
		write(2, "\n", 1);
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
	t_list	*args;

	args = content->args;
	if (args == NULL || (args->content) == NULL || ((char *)args->content)[0] == '\0')
	{
		path = ft_get_value_env(env,"HOME");
		ft_chdir(path, data, env);
		return ;
	}
	else
		path = ((char *)args->content);
	if (((char *)args->content)[0] && ((char *)args->content)[1])
	{
		data->last_exit_status = 1;

		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return ;
	}
	ft_chdir(path, data, env);
}

