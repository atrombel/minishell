
#include "cgasser.h"
#include <stdlib.h>

int	ft_make_and_fill_cmd(t_list *cmd_head, t_list **temp, char **env);
t_cmd	*ft_new_cmd();

t_list	*ft_parse(t_list *tokens, t_env *env)
{
	t_list	*cmds;
	t_list	*temp;
	int		status;

	cmds = NULL;
	ft_lstadd_back(&cmds, ft_lstnew(ft_new_cmd()));
	if (!cmds)
		return (perror(ALLOC_ERR), NULL);
	temp = tokens;
	while (temp != NULL)
	{
		status = ft_make_and_fill_cmd(cmds, &temp, env);
		if (status != 0)
			return (ft_clear_tokens(&tokens), ft_clear_cmds(&cmds), NULL);
		temp = temp->next;
	}
	ft_clear_tokens(&tokens);
	return (cmds);
}

int	ft_make_and_fill_cmd(t_list *cmds, t_list **temp, t_env *env)
{
	t_cmd	*cmd;
	t_token	*token;
	int		status;

	status = 0;
	cmd = NULL;
	token = (t_token *)(*temp)->content;
	cmd = (t_cmd *)(ft_lstlast(cmds)->content);
	if (token->type == REDIR)
		status = ft_fill_redir(cmd, temp);
	else if (token->type == PIPE)
	{
		cmd = ft_new_cmd();
		if (!cmd)
			return (perror(ALLOC_ERR), 1);
		ft_lstadd_back(&cmds, ft_lstnew(cmd));
	}
	else if (token->type == WORD)
		status = ft_fill_word(cmd, token->word, env);
	if (status == 0)
		return (0);
	return (1);
}

t_cmd	*ft_new_cmd()
{
	t_cmd	*new_cmd;

	new_cmd = NULL;
	new_cmd = ft_calloc(sizeof(t_cmd), 1);
	return (new_cmd);
}
