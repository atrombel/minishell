/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 10:36:55 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/11 19:43:47 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"
#include "cgasser.h"

//global variable to store signal
volatile sig_atomic_t	g_sig = 0;

void	main_while(t_data	data, t_env	*env)
{
	char	*user_input;
	t_list	*cmd_head;

	user_input = NULL;
	while (1)
	{
		user_input = ft_readline(env);
		if (user_input == NULL)
			break ;
		ft_history(user_input);
		cmd_head = ft_lex_and_parse(user_input, &data);
		ft_print_cmd_list(cmd_head);
		ft_exe_main(cmd_head, &data, &env);
		ft_clear_cmds(&cmd_head);
	}
	rl_clear_history();
	ft_env_clean(env);
	get_next_line(-1);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	t_data	data;

	(void)argc;
	(void)argv;
	if (ft_signals() != 0)
		return (1);
	env = init_env(envp);
	if (!env)
		return (1);
	data_init(&data, env);
	main_while(data, env);
	return (0);
}
