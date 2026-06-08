
#include "cgasser.h"

int	ft_syntax_error(char *word);
int	ft_check_pairs(t_token *current, t_token *next);

int	ft_check_syntax(t_list *tokens)
{
	t_list	*temp;
	t_token *current;
	t_token *next;

	current = NULL;
	next = NULL;
	if (!tokens)
		return (1);
	temp = tokens;
	current = (t_token *)temp->content;
	if (current->type == PIPE)
		return (ft_syntax_error(current->word), 1);
	while (temp != NULL)
	{
		current = (t_token *)temp->content;
		if (temp->next)
			next = (t_token *)(temp->next->content);
		else
			next = NULL;
		if (ft_check_pairs(current, next) != 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_syntax_error(char *word)
{
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	if (!word)
		return (ft_putstr_fd(\
		       "syntax error near unexpected token`newline'\n", 2), 1);
	s1 = ft_strjoin(word, "'\n");
	if (!s1)
		return (perror("ft_syntax_error"), 1);
	s2 = ft_strjoin("syntax error near unexpected token `", s1);
	if (!s2)
		return (free(s1), perror("ft_syntax_error"), 1);
	ft_putstr_fd(s2, 2);
	free(s1);
	free(s2);
	return (0);
}

int	ft_check_pairs(t_token *current, t_token *next)
{
	if (current->type != WORD && !next)
		return (ft_syntax_error(NULL), 1);
	if (current->type == REDIR && next->type != WORD)
		return (ft_syntax_error(next->word), 1);
	if (current->type == PIPE && next->type == PIPE)
		return (ft_syntax_error(next->word), 1);
	return (0);
}
