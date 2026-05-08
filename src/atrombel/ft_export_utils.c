#include "minishell.h"


//check si key existe deja dnas env
int	env_key_copy_check(char *new_key, t_env	*tmp_env)
{
	while (tmp_env)
	{
		if (ft_strncmp(tmp_env->key, new_key, ft_strlen(tmp_env->key)) == 0)
		{
			return (1);
		}
		tmp_env = tmp_env->next;
	}
	return (0);
}

void export_key_value(char *arg, int i , t_env *env)
{
	char	*value;
	char	*key;

	printf("\033[0;32mEntered export_key_value\033[0m\n");
	printf("arg = %s\n", arg);

	value = NULL;
	arg[i] = '\0';
	key = ft_strdup(arg); //MALLOC TO SECURE
	printf("key = %s\n", key);

	arg[i] = '=';
	value = ft_strchr(arg, '=') + 1; // securiser le retour NULL ptet idee checker le cas ou il n'y a rien apres =
	//value_validity_check(value); should be added !!!!!!
	if	(env_key_copy_check(key, env) == 1) // cas ou key existe deja dnas env
	{
		printf("\033[0;32m env_key_copy_check(key, env) == 1) donc il Y A UNE COPIE DE %s\033[0m\n", key);

		ft_change_value_env(env, key, value);

	}
	else// cas ou key nexiste pas dans env
	{
		printf("\033[0;32m pas de copie de %s\033[0m\n", key);
		ft_addnew_key_and_value(env, arg);


	}
	free(key);
}
