/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:00:19 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:00:19 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"
#include "cgasser.h"

//	exit - cause normal process termination
// a voir si rajouter data et code erreur
// return 1 if error else 0
static int	ft_isnumeric_check(const char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '-' || *s == '+' )
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

void	exit_clean(t_env *env, t_list *head, int nbr, int mode)
{
	if (mode == 1)
		ft_putstr_fd("exit\n", 1);
	ft_env_clean(env);
	ft_clear_cmds(&head);
	rl_clear_history();
	exit(nbr);
}

void	exit_err_print(char *str)
{
	ft_putstr_fd("exit\n", 1);
	error_msg("exit", str);
}

void	ft_exit(t_cmd *cmd, t_env *env, t_list *head, t_data *data)
{
	char	**args;
	int		nbr;

	nbr = 0;
	args = cmd->args;
	if (!args[1])
		exit_clean(env, head, data->last_exit_status, 1);
	if (args[2])
	{
		exit_err_print("too many arguments");
		data->last_exit_status = 1;
		return ;
	}
	if (args[0] && args[1])
	{
		if (ft_isnumeric_check(args[1]) == 0)
		{
			exit_err_print("numeric argument required\n");
			nbr = 2;
		}
		else
			nbr = ft_atoi(args[1]);
	}
	exit_clean(env, head, nbr, 0);
}
