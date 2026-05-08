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
	env = init_env(envp); // path de secour a definir sur pc ecole
	while (1)
	{
		usrinpt = readline("Waiting for a command...> ");
		token_head = ft_parse(usrinpt, envp);// change for env maybe for security
		cmd_head = ft_lst_cmd(token_head);
		ft_lstclear(&token_head, free);
		ft_print_cmd_list(cmd_head);
		ft_exe_main(cmd_head, &data, &env);// faire une fonction apres celle ci qui netooye bien tout mes trucs
		ft_lstclear(&cmd_head, ft_free_cmd);//token_head clearing function to do
	}
	ft_env_clean(env);
	return (0);
}

