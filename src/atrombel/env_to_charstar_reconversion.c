
#include "minishell.h"
#include "atrombel.h"

/// pour nettoyer apres excve penser a le mettre
void	charstar_env_clean(char **dest)
{
	int	i;

	i = 0;
	while(dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

// create a char ** taht is a conversion of t_env in env  for exceve
int	nbr_of_env_element(t_env *env_tmp)
{
	int	nbr;

	nbr = 0;
	while(env_tmp)
	{
		if (env_tmp->key && env_tmp->value)
			nbr++;
		env_tmp = env_tmp->next;
	}
	return (nbr);
}

///// Malloc, do not forget to free
char	*join_key_value(t_env *env_tmp)
{
	char *dest;
	char *tmp;

	tmp = ft_strjoin(env_tmp->key, "=");
	if (!tmp)
		return NULL;
	dest = ft_strjoin(tmp, env_tmp->value);
	free(tmp);
	if (!dest)
		return NULL;
	return (dest);
}


int	ft_env_storing(int nbr, char **dest, t_env *env_tmp)
{
	int	i;

	i = 0;
	while (env_tmp && (i < nbr))
	{
		if (env_tmp->key && env_tmp->value)
		{
			dest[i] = join_key_value(env_tmp);
			if (!dest[i])
			{
				charstar_env_clean(dest);
				return (1);
			}
			i++;
		}
		env_tmp = env_tmp->next;

	}
	dest[i] = NULL;
	return (0);
}


char	**env_to_charstar_reconversion(t_env *env)
{
	int		nbr;
	char	**dest;
	t_env	*env_tmp;

	env_tmp = env;
	nbr = nbr_of_env_element(env_tmp);
	dest = malloc(sizeof(char *) * (nbr + 1));// a secu
	if (!dest)
	{
		error_print("ERROR");
		return (NULL);
	}
	if (ft_env_storing(nbr, dest, env_tmp) == 1)
		return (NULL);
	return (dest);
}
