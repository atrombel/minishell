
#include "minishell.h"
#include "atrombel.h"

void	ft_execute_cmd(t_cmd	*cmd, t_data *data, t_env *env, t_list *head)
{
	(void)cmd;
	(void)data;
	(void)env;
	(void)head;
	// char	**envp;
	// char	**args;

	// envp = env_to_charstar_reconversion(env);
	//args = args_charstar_reconversion;
	// if (!envp)
	// {
	// 	error_print("ERROR");
	// 	return ;
	// }
	printf(" MD NOT YET DONE\n");
	//execve(cmd->path, cmd->args, envp);// attention ARGS EST PAS UN ARGUMENT IL FAUT LE RECONVERTIR // WARNING UNUSABLE RIGHT NOW BECAUSE FLAGS EN ARGUMENT ARE SORTED WHICH SHOULDNT BE, UPDATE IN PROCESS
	//error_print("execve failed");
	//
	//clean_all_there_is_to_clean();
	//exit(126);
	// /switch (errno) {
    // case EACCES:
    //     exit(126);   // fichier trouve mais pas executable
    // case ENOENT:
    //     exit(127);   // fichier introuvabl /// A CREER UNE FONCTION QUI GERE LES CODE RETOUR POUR LUI
    // default:
    //     exit(126);   // autre erreur d'exécution → 126 par convention
}

// organise execution of cmd and application of redir
void	ft_execute_cmd_redir(t_cmd	*cmd, t_data *data, t_env **env, t_list *cmd_head)
{
	int	pid;
	int	status;

	pid = fork();
	if(pid == 0)//child
	{
		if (cmd->redirs)
		{
			if (ft_redir_apply(cmd_head, data) == 0)
				ft_execute_cmd(cmd, data, env, cmd_head);
		}
		else
			ft_execute_cmd(cmd, data, env, cmd_head);
	}
	if (pid == -1)
	{
		error_print("fork");
		return ;
	}
	if (pid > 0)
	{
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
