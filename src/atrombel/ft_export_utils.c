
#include "minishell.h"
#include "atrombel.h"

void	export_printf(t_env *env_tmp)
{
	while(env_tmp)
	{
		if (env_tmp->key )
		{
			if (!env_tmp->value)
				printf("declare -x %s\n", env_tmp->key); // securiser le printf ?
			else
				printf("declare -x %s=\"%s\"\n", env_tmp->key, env_tmp->value); // securiser le printf
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
	// printf("\033[0;32m entered export key only\033[0m\n");

	if	(env_key_copy_check(arg, env) == 0)// cas ou key existe deja dnas env
		ft_addnew_key_and_value(env, arg);
	// else
	// 	printf("\033[0;32m export_key_only. donc il Y A UNE COPIE DE %s\033[0m\n", arg);

}

void	export_key_value(char *arg, int i , t_env *env)
{
	char	*value;
	char	*key;

	// printf("\033[0;32mEntered export_key_value\033[0m\n");
	// printf("arg = %s\n", arg);

	value = NULL;
	arg[i] = '\0';
	key = ft_strdup(arg); //MALLOC TO SECURE
	// printf("key = %s\n", key);
	arg[i] = '=';
	value = ft_strchr(arg, '=') + 1; // securiser le retour NULL ptet idee checker le cas ou il n'y a rien apres =
	//value_validity_check(value); should be added !!!!!!
	if	(env_key_copy_check(key, env) == 1) // cas ou key existe deja dnas env
	{
		// printf("\033[0;32m env_key_copy_check(key, env) == 1) donc il Y A UNE COPIE DE %s\033[0m\n", key);
		ft_change_value_env(env, key, value);
	}
	else// cas ou key nexiste pas dans env
	{
		// printf("\033[0;32m pas de copie de %s\033[0m\n", key);
		ft_addnew_key_and_value(env, arg);
	}
	free(key);
}

