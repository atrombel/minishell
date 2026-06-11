/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set_or_copy_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 10:09:43 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/06 10:09:43 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

t_env	*init_env_envp_exist(char **envp, t_env	*head)
{
	int		i;
	t_env	*new_node;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "_=", 2) == 0)
		{
			i++;
			continue ;
		}
		new_node = node_env_creation();
		if (!new_node || new_value_storing(envp[i], new_node) == 1)
		{
			if (new_node)
				ft_free_node(new_node);
			ft_env_clean(head);
			ft_putstr_fd("env malloc error\n", 2);
			return (NULL);
		}
		add_back_env(&head, new_node);
		i++;
	}
	return (head);
}
