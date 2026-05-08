#include "minishell.h"

// function that get the value of a key expl PWD is the key and /home/usr/minishell is the value -> warning malloc used
// maybe adding some error management to this too
char	*ft_get_value_env(t_env *env, char *str)
{
	char	*dest;

	dest = NULL;
	if (!env || !str)
		return (NULL);
	while (env && ft_strncmp(env->key, str, ft_strlen(str) + 1) != 0)
		env = env->next;
	if (env)
	{
		dest = ft_strdup(env->value); //MALLOC TO FREE
		if (!dest)
			return (NULL);
	}
	return (dest);
}

// function that changes the value  of a key expl PWD is the key and /home/usr/minishell is the value
// -> warning malloc used, maybe adding some error management to this too
void	ft_change_value_env(t_env *env, char *key, char *str)
{
	if (!env || !str || !key)
		return ;
	while (env && ft_strncmp(env->key, key, ft_strlen(key) + 1) != 0)
		env = env->next;
	if (env)
	{
		free (env->value);
		env->value = ft_strdup(str); //MALLOC TO FREE
		if (env->value)
			return ;
	}
}

// function that create a new key with it's value and put it at the end of env -> warning malloc used
// commentary : ft_strdup not secured if it fail you should clear everything including minishell
int	ft_addnew_key_and_value(t_env *env, char *str)
{
	t_env *new_node;

	if (!env || !str)
		return (1);
	while (env->next)
		env = env->next;
	new_node = node_env_creation();
	new_value_storing(str, new_node);//
	return (0);
}

// function that free env
void	ft_env_clean(t_env *env)
{
	t_env *tmp;

	tmp = NULL;
	if (env == NULL)
		return ;
	while(env != NULL)
	{
		if (env->value)
			free (env->value);
		if (env->key)
			free (env->key);
		tmp = env;
		env = env->next;
		if (tmp)
			free(tmp);
	}
}

// display all env variable that has a value
// security still to implement on printf
void	ft_env(t_data *data , t_env *env)
{
	while(env->next)
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
