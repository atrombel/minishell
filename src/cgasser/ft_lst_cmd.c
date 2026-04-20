
#include "minishell.h"
#include "cgasser.h"

//take as input a list of token,
//groupe each command with its flags and arguments
//return a list of commands
t_list	*ft_lst_cmd(t_list *head)
{
	t_list	*cmd_head;
	t_list	*temp;
	t_cmd	*new_cmd;
	t_token	*token;

	cmd_head = NULL;
	temp = NULL;
	temp = head;
	token = NULL;
	while (temp != NULL)
	{
		token = (t_token *)temp->content;
		if (token->type == CMD)
		{
			new_cmd = ft_new_cmd(token->word);
			ft_lstadd_front(&cmd_head, ft_lstnew(new_cmd));
		}
		else
			ft_fill_cmd((t_cmd *)cmd_head->content, token);
		temp = temp->next;
	}
	return (cmd_head);
}
