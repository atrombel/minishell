/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals_exe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:01:25 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:01:25 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "atrombel.h"

// ignore signals
int	set_signals_ignore()
{
	struct sigaction	sa;

	rl_catch_signals = 0;
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	if (sigemptyset(&sa.sa_mask) < 0)
		return (perror("sigset error\n"), 1);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	return (0);
}

//default signals behavior
int	set_signals_default()
{	struct sigaction	sa;

	rl_catch_signals = 0;
	sa.sa_handler = SIG_DFL;
	sa.sa_flags = 0;
	if (sigemptyset(&sa.sa_mask) < 0)
		return (perror("sigset error\n"), 1);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	return (0);

}

void	signals_heredoc(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler_heredoc;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}
void handler_heredoc(int sig)
{
	g_sig = sig;
	write(1, "\n", 1);
}
