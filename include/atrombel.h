
#ifndef ATROMBEL_H
# define ATROMBEL_H
# include <limits.h> //verifier si jai le droit dutiliser
 // sinon remove it if not used
// struct that contain usefull data to see if really that usefull long term

/* env */
t_env	*init_env(char **envp);
t_env	*node_env_creation(void);
void	add_back_env(t_env **head, t_env *new);
char	*ft_get_value_env(t_env *env, char *str);
void	ft_change_value_env(t_env *env, char *key, char *str);
void	ft_env_clean(t_env *env);
int		new_value_storing(char *envp_i, t_env *new);
int		env_key_copy_check(char *new_key, t_env *tmp_env);
char	**env_to_charstar_reconversion(t_env *env);
int		ft_addnew_key_and_value(t_env *env, char *str);
void	env_lst_cmd_update(t_env *env, char *last_arg);

/* builtins */
void	ft_echo(t_cmd *cmd,  t_data *data);
void	ft_cd(t_cmd *content, t_data *data, t_env *env);
void	ft_pwd(t_data *data, t_env *env);
void	ft_env(t_data *data, t_env *env);
void	ft_exit(t_cmd *cmd, t_env *env, t_list *head, t_data *data);
void	ft_export(t_cmd *content, t_env *env);
void	ft_unset(t_cmd *content, t_env **env);

/* export helpers */
void	export_key_value(char *arg, int i, t_env *env);
void	export_key_only(char *arg, t_env *env);
void	export_without_args(t_env *env);
void	export_printf(t_env *env_tmp);
int		export_new_value_storing(t_env *env, t_env *new);

/* heredoc */
void	heredoc_check_init(t_list *cmd_head, t_data *data);
void	heredoc_close(t_redir *redir);
void	herdoc_finder(t_list *cmd_head);
void	heredoc_tmp_deletion(t_list *cmd_head, t_data *data);

/* redirections */
void	stdin_redir(t_redir *redir, t_data *data, int *error);
void	stdout_redir(t_redir *redir, t_data *data, int *error);
void	stdout_appnd(t_redir *redir, t_data *data, int *error);
void	heredoc_reddir_apply(t_redir *redir, t_data *data, int *error);
int		ft_redir_apply(t_list *cmd_head, t_data *data);
void	fd_redir_restoration_close(t_data *data);
int		redir_but_cmd_invalid(t_list *cmd_head, t_data *data, t_cmd *cmd);

/* execution */
void	ft_exe_main(t_list *cmd_head, t_data *data, t_env **env);
void	solo_cmd(t_list *cmd_head, t_data *data, t_env **env);
void	solo_builtin(t_list *cmd_head, t_data *data, t_env **env);
void	solo_cmd_not_builtin(t_list *cmd_head, t_data *data, t_env **env);
void	multiple_cmd(t_list *cmd_head, t_data *data, t_env **env);
int		ft_builtin_verif(t_cmd *content);
int		ft_execute_builtin(t_cmd *content, t_data *data, t_env **env, t_list *head);
void	ft_execute_cmd(t_cmd *cmd, t_env **env);

/* utils */
void	data_init(t_data	*data, t_env	*envp);
char	*ft_readline(t_env *env);
void	error_print(char *str);
void	error_msg(char *str, char *msg);
void	is_minishell_lvl(t_cmd	*cmd, t_env **env);
void	command_not_found(char *str);

/* pipeline */
void	exe_pipeline(t_list *cmd_head, t_data *data, pid_t pid, t_env **env);
void	waitpid_operations(t_data *data);

/* signals*/
int	set_signals_default();
int	set_signals_ignore();

#endif
