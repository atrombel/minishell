#ifndef ATROMBEL_H
# define ATROMBEL_H
# include <limits.h> //verifier si jai le droit dutiliser
# include <errno.h> // for errno uses
// struct that contain usefull data to see if really that usefull long term

int		ft_exe_main(t_list *head, t_data *data, t_env **env);
void	ft_echo(t_cmd *cmd, t_data *data);
void	ft_cd(t_cmd *content,  t_data *data, t_env *env);
t_env	*init_env(char **envp);
char	*ft_get_value_env(t_env *env, char *str);
void	ft_change_value_env(t_env *env, char *key, char *str);
void	ft_pwd(t_data *data, t_env *env);
void	ft_env(t_data *data , t_env *env);
void	ft_env_clean(t_env *env);
void	ft_exit(t_cmd *content, t_env *env, t_list *head);
t_env	*node_env_creation();
int		new_value_storing(char *envp_i, t_env *new);
int		env_key_copy_check(char *new_key, t_env	*tmp_env);
void	ft_export(t_cmd *content, t_env *env);
void 	export_key_value(char *arg, int i , t_env *env);
int		ft_addnew_key_and_value(t_env *env, char *str);
void	export_key_only(char *arg, t_env *env);
void	add_back_env(t_env **head, t_env *new);
void	export_without_args(t_env *env);
void	export_printf(t_env *env_tmp);
int		export_new_value_storing(t_env *env, t_env *new);
void	add_back_env(t_env **head, t_env *new);
void	ft_unset(t_cmd *content, t_env **env);
char	*ft_readline(t_env *env);
int		ft_builtin_verif(t_cmd *content);
int		ft_execute_builtin(t_cmd *content, t_data *data, t_env **env, t_list *head);
void	error_print(char *str);

//data init
void	data_init(	t_data	data);

// heredocs functions

//redirection function
void	stdin_redir(t_redir	*redir,  t_data *data, int *error);
void	stdin_redir(t_redir	*redir,  t_data *data, int *error);
void	stdout_appnd(t_redir	*redir,  t_data *data, int *error);
void	heredoc_reddir_apply(t_redir	*redir,  t_data *data, int *error);

#endif
