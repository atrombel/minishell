
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

#include "libft.h"

//redirection types
#define IN 4
#define OUT 5
#define IN_DELIM 6
#define OUT_APPN 7

//error types
#define ALLOC_ERR "Error\nMemory allocation failed\n" 

// I need this struct t_env just for cd and others to work properly,
// if this wasnt there i wouldnt be able to update the PWD of my working directoy resulting desyncronasation when I call pwd
// Lors de la conversion de la liste en char envp pour fork, extraire que les variables de $type == 0$.
typedef struct s_env
{
	char			*key;	// "PWD"
	char			*value; // "/home/user"
	struct s_env	*next;
} t_env;

typedef struct s_cmd //token
{
	char	*cmd; //command name
	char	*path; //command path
	t_list	*flags; //flag(s)
	t_list	*args; //arguments
	t_list	*redirs; //redirections
}	t_cmd;

typedef struct s_redir //redirection
{
	int		type; //type of redirection (cf macro above)
	char	*arg; //filename or delimitor
}	t_redir;


#endif
