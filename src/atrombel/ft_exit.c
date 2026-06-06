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
	while(*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);

}

//tester exit ""
void	ft_exit(t_cmd *cmd, t_env *env, t_list *head, t_data *data)
{
	int		nbr;
	char	**args;

	args = cmd->args;
	nbr = EXIT_SUCCESS;// a tester en profondeur

	if (!args[1])
		exit(0);
	if (args[2])
	{
		printf("-minishell: exit: too many arguments\n"); // remplacer par un printf fans fd 2, securiser printf ?
		data->last_exit_status = 1;
		return ;
	}
	if ( args[0] && args[1])
	{

		if (ft_isnumeric_check(args[1]) == 0)
		{
			printf("-minishell: exit: %s: numeric argument required\n", args[0]); // remplacer par un printf dans fd 2 //return ; mon wsl exit quand meme a voir ubuntu ecole
			nbr = 2;
		}
		else
			nbr = ft_atoi(args[1]);
	}
	ft_env_clean(env);
	ft_clear_cmds(&head);// A DEMANDER CYRILLE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	rl_clear_history();
	exit(nbr);
}
