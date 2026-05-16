#include "minishell.h"
#include "atrombel.h"

// function that updates env if cd worked
int	cd_success(t_env *env, char *old_pwd)
{
	char	*new_wd;

	new_wd = getcwd(NULL, 0);
	if (!new_wd)
	{
		perror("minishell:cd:");
		free(old_pwd);
		return (1);
	}
	ft_change_value_env(env, "OLDPWD", old_pwd);
	free(old_pwd);
	ft_change_value_env(env, "PWD", new_wd);
	free (new_wd);
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

// check if mulitple args or not
static int	nbr_args_check(t_list	*args, t_data *data)
{
	if (args && args->content && args->next)
	{
		data->last_exit_status = 1;
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	return (0);
}

//function that determine if a path if given or not
static char	*path_define_cd(t_list	*args, t_env *env)
{
	char	*path;

	path = NULL;
	if (args == NULL || (args->content) == NULL || ((char *)args->content)[0] == '\0')
		path = ft_get_value_env(env,"HOME");
	else
		path = ((char *)args->content);
	return (path);
}

//cd args change the working directory
void	ft_cd(t_cmd *tcmd, t_data *data, t_env *env)
{
	char	*path;
	t_list	*arg;

	arg = tcmd->args;
	if (nbr_args_check(arg, data) == 1)
		return ;
	path = path_define_cd(arg, env);
	if (!path)// strong against unset HOME
	{
		data->last_exit_status = 1;
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return ;
	}
	ft_chdir(path, data, env);
}
