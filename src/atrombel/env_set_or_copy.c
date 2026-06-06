/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set_or_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:51:32 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 15:51:32 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

// create new node with malloc, return the address of the node all content of node set to NULL
t_env	*node_env_creation()
{
	t_env *node;

	node = malloc(sizeof(t_env));// TO FREE AT END OF MAIN
	if (!node)
		return (NULL);
	node->key = NULL;
	node->value = NULL;
	node->next = NULL;
	return (node);
}

// add a node at the end of the chained list
void	add_back_env(t_env **head, t_env *new)
{
	t_env *tmp;

	tmp = NULL;
	if (!new)
		return ;
	else if(!*head)
	{
		*head = new;
		return ;
	}
	else
	{
		tmp = *head;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

// function that stores the key expl PWD and value expl ./home/usr data in the node
//envp_i = for example envp_i -> WAYLAND_DISPLAY=wayland-0 key and vvalue inside
// new is for the node
// to secure ft_strdup
int	new_value_storing(char *envp_i, t_env *new)
{
	char	*sep;

	if (!envp_i || !new)
		return (0);
	sep = ft_strchr(envp_i, '=');
	if (sep == NULL)
	{
		new->key = ft_strdup(envp_i);// malloc to secure
		if (!new->key)
			return (1);
		return (0);
	}
	*sep = '\0';
	new->key = ft_strdup(envp_i);// malloc to secure
	if (!new->key)
		return (1);
	*sep = '=';
	new->value = ft_strdup(sep + 1);// malloc to secure
	if (!new->value)
		return (1);
	return (0);
}

void	ft_free_node(t_env	*node)
{
	if (node->key)
		free(node->key);
	if (node->value)
		free(node->value);
	if (node)
		free(node);
}

//copy envp into a chained list env needed for export cd etc and env -i (
/// faire gafe env ne doit garder au final (expl si je run un nouveau minshell) un env avec uniquement des key avec des value valide !)
t_env	*init_env(char **envp)
{
	t_env	*head;

	head = NULL;
	if (envp)
		head = init_env_envp_exist(envp, head);
	// else
	// {
	// 	head = emergency_env() // A CODER : une fonciton qui cree un env de secour si envp == NULL.
	return (head);
}
