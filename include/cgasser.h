
#ifndef CGASSER_H
# define CGASSER_H

# include "minishell.h"

//token types
#define WORD 1
#define REDIR 2
#define PIPE 3

typedef struct s_token //token
{
	int		type; //type, cf macro above
	char	*word; //word
}	t_token;

void	ft_history(char *user_input);
int	ft_signals(void);

char	**ft_split_quoted(char const *s, char c);

t_list	*ft_lex_and_parse(char *str, t_env *env);

t_list	*ft_parse(t_list *tokens, t_env *env);
int	ft_fill_redir(t_cmd *cmd, t_list **temp);
int	ft_fill_word(t_cmd *cmd, char *word, t_env *env);
int	ft_fill_cmd(t_cmd *cmd, char *word, t_env *env);

int	ft_is_redir(char *str);

void	ft_print_cmd_list(t_list *head);

void	ft_clear_cmds(t_list **cmds);
void	ft_clear_tokens(t_list **tokens);

char	*ft_trim_quotes(char *str);


#endif
