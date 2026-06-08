/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:51:54 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/08 16:50:27 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free (old_pwd);
	ft_change_value_env(env, "PWD", new_wd);
	free (new_wd);
	return (0);
}

// function that actually changes current working
// directory and update pwd and oldpwd fomr env
void	ft_chdir(char	*path, t_data *data, t_env *env)
{
	char	*old_pwd;

	if (chdir(path) == -1)
	{
		error_msg("cd", "No such file or directory");
		data->last_exit_status = 1;
		return ;
	}
	else
	{
		old_pwd = ft_get_value_env(env, "PWD");
		if (cd_success(env, old_pwd) == 1)
			data->last_exit_status = 1;
		else
			data->last_exit_status = 0;
	}
}

// check if mulitple args or not
static int	nbr_args_check(char	**args, t_data *data)
{
	if (args && args[0] && args[1] && args[2])
	{
		error_msg("cd", "too many arguments");
		data->last_exit_status = 1;
		return (1);
	}
	return (0);
}

//function that determine if a path if given or not and returns it
static char	*path_define_cd(char **args, t_env *env)
{
	char	*path;

	path = NULL;
	if (args[1] == NULL)
		path = ft_get_value_env(env, "HOME");
	else
		path = args[1];
	return (path);
}

//cd args change the working directory
void	ft_cd(t_cmd *cmd, t_data *data, t_env *env)
{
	char	*path;
	char	**args;

	args = cmd->args;
	if (nbr_args_check(args, data) == 1)
		return ;
	path = path_define_cd(args, env);
	if (!path)
	{
		error_msg("cd", "HOME not set");
		data->last_exit_status = 1;
		return ;
	}
	ft_chdir(path, data, env);
}
