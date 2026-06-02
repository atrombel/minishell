#include "minishell.h"
#include "atrombel.h"

void	multiple_cmd(t_list *cmd_head, t_data *data, t_env **env)
{
	pid_t pid;


	while(cmd_head && cmd_head->next)
	{
		if (cmd_head->content)
			exe_pipeline(cmd_head, t_data *data, pid);

		cmd_head = cmd_head->next;
	}

	// (void)cmd_head;
	// (void)data;
	// (void)env;
	// printf("work in progress come back later\n");
}
