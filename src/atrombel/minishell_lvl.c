/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lvl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:13 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:01:13 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "atrombel.h"

void	is_minishell_lvl(t_cmd	*cmd, t_env **env)
{
	char	*shlvl_str;
	char	*new_value;
	int		value;

	new_value = NULL;
	if (ft_strncmp(cmd->args[0], "minishell", 10) == 0)
	{
		shlvl_str = ft_get_value_env(*env, "SHLVL");
		if (shlvl_str)
			value = ft_atoi(shlvl_str) + 1;
		else
			value = 1;
		new_value = ft_itoa(value);
		if (!new_value)
			return ;
		ft_change_value_env(*env, "SHLVL", new_value);
	}
}
