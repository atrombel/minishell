/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:00:21 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/11 20:06:17 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <errno.h>

//redirection types
//---------------------------------------------------
// IN 4 //"<"
// OUT 5 //">"
// IN_DELIM 6 // "<<"
// OUT_APPN 7 //">>"
# define IN 4
# define OUT 5
# define IN_DELIM 6
# define OUT_APPN 7

//global variable to store signals
extern volatile sig_atomic_t	g_sig;

//env
//---------------------------------------------------
//key expl "PWD"
//value expl "/home/user"
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

// data storage
//---------------------------------------------------
typedef struct s_data
{
	int		last_exit_status;
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	int		stdin_save;
	int		stdout_save;
	int		tmp_fd;
	int		last_hd_nbr;
	t_env	*env;
}	t_data;

//cmds
//---------------------------------------------------
// is_valid; //1 if it is a valid command, 0 otherwise
// path; //command path
// args; //name of the command, flag and arguments
// redirs; //redirections
typedef struct s_cmd
{
	int		is_valid;
	char	*path;
	char	**args;
	t_list	*redirs;
}	t_cmd;

//redirection
//---------------------------------------------------
// type; type of redirection (cf macro above)
// hd_tmp_fd;  fd of the associated heredoc
// is_expanded; 1 if the heredoc must expand its variables
// is_ambiguous; 1 if the redirection is ambiguous
// arg; filename or delimitor
// hd_filename; heredoc temporary file created to store the
// input of the user associated to a command MALLOC

//redir
//---------------------------------------------------
typedef struct s_redir
{
	int		type;
	int		hd_tmp_fd;
	int		is_expanded;
	int		is_ambiguous;
	char	*arg;
	char	*hd_filename;
}	t_redir;

char	*ft_expand_var(char *str, t_data *data);
char	*ft_get_value_env(t_env *env, char *str);

#endif
