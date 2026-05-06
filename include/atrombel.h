#ifndef ATROMBEL_H
# define ATROMBEL_H

// struct that contain usefull data
typedef struct s_data
{
	int last_exit_status;

} t_data;

// I need this struct t_env just for cd and others to work properly,
// if this wasnt there i wouldnt be able to update the PWD of my working directoy resulting desyncronasation when I call pwd
typedef struct s_env
{
	char			*key;	// "PWD"
	char			*value; // "/home/user"
	struct s_env	*next;
} t_env;

void	ft_exe_main(t_list *head, t_data *data,t_env *env);
void	ft_echo(t_cmd *cmd, t_data *data);
void	ft_cd(t_cmd *cmd);
t_env	*init_env(char **envp);



#endif
