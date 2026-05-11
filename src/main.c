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
	char	*user_input;
	t_list	*cmd_head;

	user_input = NULL;
	(void)argc;
	(void)argv;
	while (1)
	{
		user_input = readline("Waiting for a command...> ");
		cmd_head = ft_lex_and_parse(user_input, envp);
		ft_print_cmd_list(cmd_head);
		ft_clear_cmds(&cmd_head);
	}
	return (0);
}
