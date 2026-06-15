/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:00:21 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/15 09:00:49 by atrombel         ###   ########.fr       */
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
# define HEREDOC 6
# define APPEND 7

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
	pid_t	last_pid;
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

//struct used in ft_expand_var
typedef struct s_expand
{
	int		i;
	int		j;
	int		quote;
	char	*value;
}	t_expand;

char	*ft_expand_var(char *str, t_data *data);
void	ft_init_exp(t_expand *exp);
void	ft_update_quote(t_expand *exp, char c);
char	*ft_get_value(char *start, t_data *data);
int		ft_strlen_varname(char *start);
void	ft_incr_indexes(t_expand *exp);

char	*ft_get_value_env(t_env *env, char *str);

#endif
