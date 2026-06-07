/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:00:33 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:00:33 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

int	export_new_value_storing(t_env *env, t_env *new)
{
	if (!env || !new)
		return (0);
	if (!env->value && env->key)
	{
		new->key = ft_strdup(env->key);// malloc to secure
		if (!new->key)
			return (1);
		return (0);
	}
	new->key = ft_strdup(env->key);// malloc to secure
	if (!new->key)
		return (1);
	new->value = ft_strdup(env->value);// malloc to secure
	if (!new->value)
		return (1);
	return (0);
}

// ATTENTION SI JE TAPE EXPORT a= PUIS EXPORT, export doit me display a=""
void	export_with_args(char *arg, t_env *env, t_data *data)
{
	int		i;

	i = 0;
	if (ft_isalpha(arg[0]) == 0 && arg[0] != '_')// check du premier char
	{
		if (arg[0] == '\0')
			printf("-minishell: export: ': not a valid identifier\n");
		else
			printf("-minishell: export: '%s': not a valid identifier\n", arg);
		data->last_exit_status = 1;
		return ;
	}
	while(arg[i] != '=' && arg[i])//check if key is valid
	{
		if (ft_isalpha(arg[0]) == 0 && arg[0] == '_' && ft_isdigit(arg[i]) == 1)
		{
			printf("-minishell: export: '%s': not a valid XD identifier\n", arg);
			data->last_exit_status = 1;
			return ;
		}
		i++;
	}
	if (arg[i] == '=') // since key is valid and there is a '=' so value exist or is at least "".
		export_key_value(arg, i, env, data);
	else
		export_key_only(arg, env);
	return ;
}

// la commande seule $export affiche tout env dans lordre avec delcare -x au debut
// faire une copie et la trier
void	ft_export(t_cmd *cmd, t_env *env, t_data *data)
{
	int		i;
	char	**args;

	args = cmd->args;
	i = 1;
	if (!args[1] || !args[1][0])
	{
		export_without_args(env);
		return ;
	}
	while(args[i])
	{
		export_with_args(args[i], env, data);
		i++;
	}
}
