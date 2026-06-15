/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:52:11 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 15:52:11 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

// function that get the value of a key
// expl PWD is the key
// and /home/usr/minishell is the value -> warning malloc used
// str is the key
// maybe adding some error management to this too
char	*ft_get_value_env(t_env *env, char *str)
{
	char	*dest;

	dest = NULL;
	if (!env || !str)
		return (NULL);
	while (env && (!env->key
			|| ft_strncmp(env->key, str, ft_strlen(str) + 1) != 0))
		env = env->next;
	if (env)
	{
		dest = ft_strdup(env->value);
		if (!dest)
			return (NULL);
	}
	return (dest);
}

// function that changes the value  of a key
// expl PWD is the key and /home/usr/minishell is the value
// -> warning malloc used
void	ft_change_value_env(t_env *env, char *key, char *str)
{
	char	*new_value;

	if (!env || !str || !key)
		return ;
	while (env && ft_strncmp(env->key, key, ft_strlen(key) + 1) != 0)
		env = env->next;
	if (env)
	{
		new_value = ft_strdup(str);
		if (!new_value)
			return ;
		free(env->value);
		env->value = new_value;
	}
}

// function that create a new key with it's value
//  and put it at the end of env -> warning malloc used
// commentary : ft_strdup not secured if it fail then you
//  should clear everything including minishell
int	ft_addnew_key_and_value(t_env *env, char *str)
{
	t_env	*new_node;

	if (!env || !str)
		return (1);
	while (env->next)
		env = env->next;
	new_node = node_env_creation();
	if (!new_node)
		return (1);
	if (new_value_storing(str, new_node) == 1)
		return (1);
	env->next = new_node;
	return (0);
}

// function that free env
void	ft_env_clean(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}

// display all env variable that has a value
// security still to implement on printf
void	ft_env(t_data *data, t_env *env)
{
	while (env)
	{
		if (env->key && env->value)
		{
			if (printf("%s=%s\n", env->key, env->value) == -1)
			{
				data->last_exit_status = 1;
				return ;
			}
		}
		env = env->next;
	}
}
