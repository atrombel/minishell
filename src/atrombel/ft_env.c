#include "minishell.h"

// function that get the value of a key expl PWD is the key and /home/usr/minishell is the value
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
	//printf("ft_get_value dest me retourne %s\n", dest);
	return (dest);
}

// function that changes the value  of a key expl PWD is the key and /home/usr/minishell is the value
// maybe adding some error management to this too
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
		//printf("ft_change_value  me retourne  env->value = %s\n", env->value);
		if (env->value)
			return ;
	}
}

// function that free env
void	ft_env_clean(t_env *env)
{
	t_env *tmp;

	tmp = NULL;
	while(env != NULL)
	{
		if (env->value)
			free (env->value);
		if (env->key)
			free (env->key);
		tmp = env;
		env = env->next;
		free(tmp);
	}
}

void	ft_env(t_data *data , t_env *env)
{
	while(env->next)
	{
		if (printf("%s=%s\n", env->key, env->value) == -1)
		{
			data->last_exit_status = 1;
			return ;
		}
		env = env->next;
	}
}
