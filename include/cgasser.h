
#ifndef CGASSER_H
# define CGASSER_H

# include "libft.h"

//token types
#define CMD 0
#define FLAG 1
#define ARG 2

typedef struct s_token //token
{
	char	*word; //word
	int		type; //type, cf macro above
	int		index; //index in the input string
}	t_token;

typedef struct s_cmd //token
{
	char	*cmd; //command name
	char	**flag; //flag(s)
	char	**args; //arguments
}	t_cmd;

t_list	*ft_parse(char *str, char **envp);
t_list	*ft_list_token(char **array, char **envp);
t_token	*ft_tokenize(char *str, int index, char **envp);
int		ft_get_type(t_token *token, char **envp);
int		ft_check_cmd(t_token *token, char **envp);
int		ft_cmd_cmp(t_token *token, char **envp);

t_list	*ft_lst_cmd(t_list *head);
void	ft_fill_cmd(t_cmd *head, t_token *token);
t_cmd	*ft_new_cmd(char *word);
void	ft_free_cmd(void *cmd);

void	ft_print_token_lst(t_list *head);
void	ft_print_cmd_list(t_list *head);

#endif
