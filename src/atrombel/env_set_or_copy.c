#include "minishell.h"

// create new node with malloc
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
	// printf("\033[0;32m new_value_storing entered\033[0m\n");

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

// function taht copy envp into a chained list env needed for export cd etc and env -i (pas oublier de faire une fonciton qui libere tout ca)
/// faire gafe env ne doit garder au final (expl si je run un nouveau minshell un env avec uniquement des key avec des value valide !)
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
			new = node_env_creation();
			if (new_value_storing(envp[i], new) == 1)
			{
				ft_env_clean(head);
				exit(1);// to check if good idea or not
			}
			add_back_env(&head, new);
			i++;
		}
	}
	// else
	// {
	// 	head = emergency_env() // A CODER : une fonciton qui cree un env de secour si envp == NULL.
	return (head);
}
