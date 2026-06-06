/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:03 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:01:03 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

t_env	*find_prev_node(t_env *env, char *str)
{
	t_env	*precedent_node;

	precedent_node = NULL;
	if (!env || !str)
		return (NULL);
	precedent_node = env;
	while (env && ft_strncmp(env->key, str, ft_strlen(str) + 1) != 0)
	{
		precedent_node = env;
		env = env->next;
	}
	if (env == NULL)
		return (NULL);
	else
		return (precedent_node);
}

void	free_node_env(t_env *node)
{
	if (node)
	{
		free(node->value);
		free(node->key);
		free(node);
	}
}

void	ft_unset(t_cmd *cmd, t_env **env)
{
	int		i;
	t_env	*prev_node;
	t_env	*current_node;
	char	**args;

	args = cmd->args;
	i = 1;
	if (!args[1] || !args[1][0])
			return;
	while (args[i])
	{
		prev_node = find_prev_node(*env, args[i]);
		if (prev_node == NULL)
			return ;
		else if (prev_node->key == (*env)->key)// alors on doit changer head car on est au debut de la liste
		{
			*env = (*env)->next;
			free_node_env(prev_node);
		}
		else
		{
			current_node = prev_node->next;
			prev_node->next = current_node->next;
			free_node_env(current_node);
		}
		i++;
	}
}
