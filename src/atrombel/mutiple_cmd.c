#include "minishell.h"
#include "atrombel.h"

void	multiple_cmd(t_list *cmd_head, t_data *data, t_env **env)
{
	pid_t pid;

	pid = -1;
	while (cmd_head)
	{
		if (cmd_head->content)
			exe_pipeline(cmd_head, data, pid, env);
		cmd_head = cmd_head->next;
	}
}
