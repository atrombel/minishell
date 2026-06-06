/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_charstar_reconversion.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:51:36 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 15:51:36 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
int	nbr_of_env_element(t_env *env)
{
	int	nbr;

	nbr = 0;
	while(env)
	{
		if (env->key && env->value)
			nbr++;
		env = env->next;
	}
	return (nbr);
}

///// Malloc, do not forget to free
char	*join_key_value(t_env *env)
{
	char *dest;
	char *tmp;

	tmp = ft_strjoin(env->key, "=");
	if (!tmp)
		return NULL;
	dest = ft_strjoin(tmp, env->value);
	free(tmp);
	if (!dest)
		return NULL;
	return (dest);
}


int	ft_env_storing(int nbr, char **dest, t_env *env)
{
	int	i;

	i = 0;
	while (env && (i < nbr))
	{
		if (env->key && env->value)
		{
			dest[i] = join_key_value(env);
			if (!dest[i])
			{
				charstar_env_clean(dest);
				return (1);
			}
			i++;
		}
		env = env->next;

	}
	dest[i] = NULL;
	return (0);
}

// converts a t_env linked list into a char** array formatted as "KEY=VALUE"
// suitable for use with execve. returns null on allocation failure
// WARNING the returned array must be freed with charstar_env_clean() after use !!!!!!!!!!!!!!!
char	**env_to_charstar_reconversion(t_env *env)
{
	int		nbr;
	char	**dest;

	nbr = nbr_of_env_element(env);
	dest = malloc(sizeof(char *) * (nbr + 1));
	if (!dest)
	{
	error_print("ERROR");
		return (NULL);
	}
	if (ft_env_storing(nbr, dest, env) == 1)
		return (NULL);
	return (dest);
}
