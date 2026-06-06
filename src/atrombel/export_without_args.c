/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_without_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:51:50 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 15:51:50 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

// ft_strlen of 2 distinct string but return the longest one only
static int	strlen_max(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (j > i)
		return (j);
	else
		return (i);
}

// swapp 2 node if a->b then it will become b->a
static void	ft_swap_env(t_env *a, t_env *b)
{
	char	*tmp_key;
	char	*tmp_value;

	tmp_key = a->key;
	tmp_value = a->value;

	a->key = b->key;
	a->value = b->value;
	b->key = tmp_key;
	b->value = tmp_value;
}

// sorting of a t_env chained list, herer used for the command export without args
void	export_only_sorting(t_env *env_tmp)
{
	int		swapped;
	t_env	*current;

	swapped = 1;
	while(swapped)
	{
		swapped = 0;
		current = env_tmp;
		while(current->next)
		{
			if(ft_strncmp(current->key, current->next->key, strlen_max(current->key, current->next->key)) > 0)
			{
				ft_swap_env(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
	}
}

// copy a chained list of struct t_env and return the head of it
t_env	*export_only_env_copy(t_env *env)
{
	t_env *head;
	t_env *new;

	new = NULL;
	head = NULL;
	while(env)
	{
		new = node_env_creation();
		if (export_new_value_storing(env, new) == 1)// a securiser
			{
				ft_env_clean(head);
				exit(1);// to check if good idea or not
			}
		add_back_env(&head, new);
		env=env->next;
	}
	return (head);
}

// function that manage operation process when export doesnt have args
void	export_without_args(t_env *env)
{
	t_env *env_tmp;

	env_tmp = NULL;
	// printf("\033[0;32m hello\033[0m\n");
	env_tmp = export_only_env_copy(env);
	if (!env_tmp)
		return ; //voir si modif a faire
	export_only_sorting(env_tmp);
	export_printf(env_tmp);
	ft_env_clean(env_tmp);
}
