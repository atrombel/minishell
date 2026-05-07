/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:12:44 by atrombel          #+#    #+#             */
/*   Updated: 2026/04/09 13:12:52 by atrombel         ###   ###lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	char	*usrinpt;
	t_list	*token_head;
	t_list	*cmd_head;
	t_env	*env;
	t_data	data;

	usrinpt = NULL;
	(void)argc;
	(void)argv;
	env = init_env(envp); //FAIRE UN builtin de la commande ENV a partir de ca / path de secour a definir sur pc ecole creer un ft_env_clear_aussi
	while (1)
	{
		usrinpt = readline("Waiting for a command...> ");
		token_head = ft_parse(usrinpt, envp);// change for env maybe for security
		cmd_head = ft_lst_cmd(token_head);
		ft_lstclear(&token_head, free);
		ft_print_cmd_list(cmd_head);
		ft_exe_main(cmd_head, &data, env);// data last command error number "echo $?"" to implement
		ft_lstclear(&cmd_head, ft_free_cmd);
	}
	return (0);
}
