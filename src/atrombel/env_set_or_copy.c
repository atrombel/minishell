#include "minishell.h"

// create new node with malloc
t_env	*node_creation()
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
void	add_back(t_env **head, t_env *new)
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
void	new_value_storing(char *envp_i, t_env *new)
{
	char	*sep;

	sep = ft_strchr(envp_i, '=');
	*sep = '\0';
	new->key = ft_strdup(envp_i);// malloc to secure
	*sep = '=';
	new->value = ft_strdup(sep + 1);// malloc to secure
}

// function taht copy envp into a chained list env needed for export cd etc and env -i (pas oublier de faire une fonciton qui libere tout ca)
t_env	*init_env(char **envp)
{
	int		i;
	t_env	*head;
	t_env	*new;

	i = 0;
	head = NULL;
	if (envp)
	{
		while(envp[i])
		{
			new = node_creation();
			new_value_storing(envp[i], new);
			add_back(&head, new);
			i++;
		}
	}
	// else
	// {
	// 	head = emergency_env() // A CODER : une fonciton qui cree un env de secour si envp == NULL.
	return (head);
}
