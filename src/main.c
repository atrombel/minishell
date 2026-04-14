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

int	main(int argc, char **argv, char **env)
{
	char	*usrinpt;

	usrinpt = NULL;
	(void)argc;
	(void)argv;
	(void)env;
	while (1)
	{
		usrinpt = readline("Waiting for a command...> ");
		printf("%s\n", usrinpt);
	}
	return (0);

	//ft_parse(argc, argv);
}
