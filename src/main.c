#include "minishell.h"
#include "atrombel.h"
#include "cgasser.h"
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	char	*user_input;
	t_list	*cmd_head;
	t_env	*env;
	t_data	data;
	struct sigaction	sa;

	sa.sa_sigaction = ft_signals;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	user_input = NULL;
	(void)argc;
	(void)argv;
	ft_signals();
	env = init_env(envp); // path de secour a definir sur pc ecole
	while (1)
	{
		user_input = ft_readline(env);
		if (user_input == NULL)
			break ;
		cmd_head = ft_lex_and_parse(user_input, env);
		ft_print_cmd_list(cmd_head);
		ft_exe_main(cmd_head, &data, &env);// faire une fonction apres celle ci qui netooye bien tout mes trucs
		ft_clear_cmds(&cmd_head);
	}
	ft_env_clean(env);
	return (0);
}

