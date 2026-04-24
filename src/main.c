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

	usrinpt = NULL;
	(void)argc;
	(void)argv;
	while (1)
	{
		usrinpt = readline("Waiting for a command...> ");
		token_head = ft_parse(usrinpt, envp);
		cmd_head = ft_lst_cmd(token_head);
		ft_lstclear(&token_head, free);
		ft_print_cmd_list(cmd_head);
		ft_lstclear(&cmd_head, ft_free_cmd);
	}
	return (0);
}
