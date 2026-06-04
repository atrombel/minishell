
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
