
#include "minishell.h"
#include "cgasser.h"

void	ft_free_token(void *content);

void	ft_clear_tokens(t_list **tokens)
{
	ft_lstclear(tokens, ft_free_token);
}

void	ft_free_token(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	free(token->word);
	free(token);
}
