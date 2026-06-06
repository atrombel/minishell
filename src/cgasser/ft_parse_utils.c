
#include "cgasser.h"

t_redir	*ft_new_redir();

int	ft_fill_redir(t_cmd *cmd, t_list **temp)
{
	t_redir	*redir;
	t_token	*token;

	token = (t_token *)(*temp)->content;
	redir = NULL;
	redir = ft_new_redir();
	if (!redir)
		return (perror("ft_fill_redir"), 1);
	redir->type = ft_is_redir(token->word);
	if (!((*temp)->next))
		return (1);
	if (!((*temp)->next))
		return (1);
	*temp = (*temp)->next;
	token = (t_token *)(*temp)->content;
	if (token->type == PIPE)
		return (1);
	redir->arg = ft_calloc(sizeof(char), ft_strlen(token->word) + 1);
	if (!redir->arg)
		return (perror("ft_fill_redir"), 1);
	ft_strlcpy(redir->arg, token->word, ft_strlen(token->word) + 1);
	redir->hd_filename = NULL;
	redir->hd_tmp_fd = -1;
	ft_lstadd_back(&cmd->redirs, ft_lstnew(redir));
	return (0);
}

t_redir	*ft_new_redir()
{
	t_redir	*new_redir;

	new_redir = NULL;
	new_redir = ft_calloc(sizeof(t_redir), 1);
	return (new_redir);
}
