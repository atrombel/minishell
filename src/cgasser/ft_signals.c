
#include "cgasser.h"

void	ft_handler(int sig);

int	ft_signals(void)
{
	struct sigaction	sa;

	rl_catch_signals = 0;
	sa.sa_handler = ft_handler;
	sa.sa_flags = 0;
	if (sigemptyset(&sa.sa_mask) < 0)
		return (perror("sigset error\n"), 1);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	return (0);
}

void	ft_handler(int sig)
{
	g_sig = sig;
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
