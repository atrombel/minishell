
#ifndef CGASSER_H
# define CGASSER_H

# include "libft.h"

//token types
#define WORD 1
#define REDIR 2
#define PIPE 3

//redirection types
#define IN 4
#define OUT 5
#define IN_DELIM 6
#define OUT_APPN 7

//error types
#define ALLOC_ERR "Error\nMemory allocation failed\n" 

#define WRG_CMD "Error\nUnvalid command: '%s'\n" 

typedef struct s_token //token
{
	int		type; //type, cf macro above
	char	*word; //word
}	t_token;

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

char	**ft_split_quoted(char const *s, char c);

t_list	*ft_lex_and_parse(char *str, char **envp);

t_list	*ft_parse(t_list *tokens, char **envp);
int	ft_fill_redir(t_cmd *cmd, t_list **temp);
int	ft_fill_word(t_cmd *cmd, char *word, char **envp);
int	ft_fill_cmd(t_cmd *cmd, char *word, char **envp);

int	ft_is_redir(char *str);

void	ft_print_cmd_list(t_list *head);

void	ft_clear_cmds(t_list **cmds);
void	ft_clear_tokens(t_list **tokens);

char	*ft_expand_var(char *str, char **envp);

#endif
