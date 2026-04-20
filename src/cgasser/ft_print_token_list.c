

#include "minishell.h"
#include "ft_printf.h"

void	ft_print_token_lst(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		ft_printf("%s, %d, %d\n", ((t_token *)(temp->content))->word, ((t_token *)(temp->content))->index, ((t_token *)(temp->content))->type);
		temp = temp->next;
	}
}
