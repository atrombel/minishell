
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "libft.h"
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <errno.h> // for errno uses

//redirection types
# define IN 4 //"<"
# define OUT 5 //">"
# define IN_DELIM 6 // "<<"
# define OUT_APPN 7 //">>"
//error types
# define ALLOC_ERR "Error\nMemory allocation failed\n"

//global variable to store signals
extern volatile sig_atomic_t g_sig;

typedef struct s_env
{
	char			*key;	// "PWD"
	char			*value; // "/home/user"
	struct s_env	*next;
} t_env;

// I need this struct t_env just for cd and others to work properly,
// if this wasnt there i wouldnt be able to update the PWD of my working directoy resulting desyncronasation when I call pwd
// Lors de la conversion de la liste en char envp pour fork, extraire que les variables de $type == 0$.
typedef struct s_data// prblmt que je vais devoir le mettre en init pour chaque argument donc data sera seuelemt pour last exist status'
{
	int		last_exit_status;
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	int		stdin_save;
	int		stdout_save;
	int		tmp_fd;
	int		last_hd_nbr; // suffixe du tmp por plusieur heredoc
	t_env	*env;
} t_data;

typedef struct s_cmd
{
	char	*path; //command path
	char	**args; //name of the command, flag and arguments
	t_list	*redirs; //redirections
}	t_cmd;

typedef struct s_redir //redirection
{
	int		type; //type of redirection (cf macro above)
	char	*arg; //filename or delimitor
	char	*hd_filename; //heredoc temporary file created to store the input of the user associated to a command MALLOC
	int		hd_tmp_fd; // le fd du heredoc associe
}	t_redir;

char	*ft_expand_var(char *str, t_data *data);

#endif
