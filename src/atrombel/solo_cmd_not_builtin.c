
#include "minishell.h"
#include "atrombel.h"

void	ft_execute_cmd(t_cmd	*cmd, t_data *data, t_env **env, t_list *head)
{
	(void)data;
	(void)head;
	char	**envp;

	envp = env_to_charstar_reconversion(*env);
	if (!envp)
	{
		error_print("ERROR");
		return ;
	}
	execve(cmd->path, cmd->args, envp);
	error_print("execve failed");
	// penser a free envp
	// clean_all_there_is_to_clean(); A FAIRE
	// exit(126);
	// /switch (errno) {
	// case EACCES:
	// 	exit(126);   // fichier trouve mais pas executable
	// case ENOENT:
	// 	exit(127);   // fichier introuvabl /// A CREER UNE FONCTION QUI GERE LES CODE RETOUR POUR LUI
	// default:
	// 	exit(126);   // autre erreur d'exécution → 126 par convention
}

// organise execution of cmd and application of redir
void	ft_execute_cmd_redir(t_cmd	*cmd, t_data *data, t_env **env, t_list *cmd_head)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
	{
		error_print("fork");
		return ;
	}
	if(pid == 0)//child
	{	write(1, "\033[32m[DEBUG] je suis passé ici\n\033[0m", 37);

		if (cmd->redirs)
		{
			if (ft_redir_apply(cmd_head, data) == 0)
				ft_execute_cmd(cmd, data, env, cmd_head);
		}
		else
			ft_execute_cmd(cmd, data, env, cmd_head);
		exit(126);
	}

	if (pid > 0)
	{
		write(1, "\033[35m[DEBUG] je suis passé ici\n\033[0m", 37);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			data->last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			data->last_exit_status = 128 + WTERMSIG(status);
	}
}

void	solo_cmd_not_builtin(t_list *cmd_head, t_data *data, t_env **env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)cmd_head->content;
	ft_execute_cmd_redir(cmd, data, env, cmd_head);
	heredoc_tmp_deletion(cmd_head);

}
