/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   emergency_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:27:39 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/07 15:27:39 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

static void	free_envp_tab(char **envp, int i)
{
	while (i >= 0)
	{
		if (envp[i])
			free(envp[i]);
		i--;
	}
	free(envp);
}

static char	**init_envp_tab(void)
{
	char	**envp;
	char	*pwd;
	char	*str;

	str = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	envp = malloc(sizeof(char *) * 6);
	if (!envp)
		return (NULL);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = ft_strdup("/");
	if (!pwd)
		return (free(envp), NULL);
	envp[0] = ft_strdup("SHELL=/bin/minishell");
	envp[1] = ft_strdup(str);
	envp[2] = ft_strjoin("PWD=", pwd);
	envp[3] = ft_strdup("OLDPWD=");
	envp[4] = ft_strdup("SHLVL=1");
	envp[5] = NULL;
	free(pwd);
	if (!envp[0] || !envp[1] || !envp[2] || !envp[3] || !envp[4])
		return (free_envp_tab(envp, 4), NULL);
	return (envp);
}

// if env doesnt exist for some reason ...
t_env	*emergency_env(t_env *head)
{
	char	**envp;
	t_env	*new_node;
	int		i;

	envp = init_envp_tab();
	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		new_node = node_env_creation();
		if (!new_node || new_value_storing(envp[i], new_node) == 1)
			return (ft_free_node(new_node), ft_env_clean(head),
				free_envp_tab(envp, 4), NULL);
		add_back_env(&head, new_node);
		i++;
	}
	return (free_envp_tab(envp, 4), head);
}
