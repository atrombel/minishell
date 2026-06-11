/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:51:44 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 15:51:44 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

// str doit etre la commande le nom de fricheir etc un char * du probleme
void	command_not_found(char *str)
{
	if (!str)
		return ;
	ft_putstr_fd(str, 2);
	write(2, ": ", 2);
	ft_putstr_fd("command not found", 2);
	write(2, "\n", 1);
}

// for errno
void	error_print(char *str)
{
	if (!str)
		return ;
	write(2, "minishell: ", 11);
	ft_putstr_fd(str, 2);
	write(2, ": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	write(2, "\n", 1);
}

// sans strerror pour les erreurs  logiques
void	error_msg(char *str, char *msg)
{
	if (!str || !msg)
		return ;
	write(2, "minishell: ", 11);
	ft_putstr_fd(str, 2);
	write(2, ": ", 2);
	ft_putstr_fd(msg, 2);
	write(2, "\n", 1);
}
