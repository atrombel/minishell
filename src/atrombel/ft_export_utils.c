/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:00:26 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:00:26 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

void	export_printf(t_env *env_tmp)
{
	while (env_tmp)
	{
		if (env_tmp->key)
		{
			if (!env_tmp->value)
				printf("declare -x %s=\"\"\n", env_tmp->key);
			else
				printf("declare -x %s=\"%s\"\n", env_tmp->key, env_tmp->value);
		}
		env_tmp = env_tmp->next;
	}
}

//check si key existe deja dnas env
int	env_key_copy_check(char *new_key, t_env	*tmp_env)
{
	while (tmp_env)
	{
		if (ft_strncmp(tmp_env->key, new_key, ft_strlen(tmp_env->key)) == 0)
			return (1);
		tmp_env = tmp_env->next;
	}
	return (0);
}

void	export_key_only(char *arg, t_env *env)
{
	if (env_key_copy_check(arg, env) == 0)
	{
		if (ft_addnew_key_and_value(env, arg) == 1)
		{
			error_msg("export", "new key allocation failed");
			return ;
		}
	}
}

void	export_key_value(char *arg, int i, t_env *env, t_data *data)
{
	char	*value;
	char	*key;

	value = NULL;
	arg[i] = '\0';
	key = ft_strdup(arg);
	if (!key)
		return (data->last_exit_status = 1, perror("export_key_value"));
	arg[i] = '=';
	value = ft_strchr(arg, '=') + 1;
	if (!value)
	{
		free (key);
		return ;
	}
	if (env_key_copy_check(key, env) == 1)
		ft_change_value_env(env, key, value);
	if (ft_addnew_key_and_value(env, arg) == 1)
		data->last_exit_status = 1;
	free(key);
}
