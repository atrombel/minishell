
#include "minishell.h"

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
	// printf("\033[0;32m export_only_env_copy closed ok \033[0m\n");
	// write(1, "1\n", 2);
	return (head);

}

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
