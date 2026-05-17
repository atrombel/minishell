#include "minishell.h"
#include "atrombel.h"
#include "cgasser.h"
#include <stdlib.h>
#include "ft_printf.h"

//global variable to store signal
volatile sig_atomic_t g_sig = 0;

int	main(int argc, char **argv, char **envp)
{
	char	*user_input;
	t_list	*cmd_head;
	t_env	*env;
	t_data	data;
	struct sigaction	sa;

	(void)argc;
	(void)argv;
	user_input = NULL;
	rl_catch_signals = 0;
	sa.sa_handler = ft_handler;
	sa.sa_flags = 0;
	if (sigemptyset(&sa.sa_mask) < 0)
		return (perror("sigset error\n"), 1);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	env = init_env(envp);
	while (1)
	{
		user_input = readline("Waiting for a command...> ");
		if (user_input == NULL)
			return (rl_clear_history(), 0);
		if (user_input[0] != '\0')
			add_history(user_input);
		cmd_head = ft_lex_and_parse(user_input, env);
		ft_print_cmd_list(cmd_head);
		ft_exe_main(cmd_head, &data, &env);
		ft_clear_cmds(&cmd_head);
	}
	ft_env_clean(env); //ligne non executée
	return (0);
}


// à mettre dans ft_exit: rl_clear_history()
// last exit status: g_sig?

