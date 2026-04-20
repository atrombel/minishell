
#include "minishell.h"
#include "cgasser.h"
#include <stdlib.h>
#include "ft_printf.h"

t_list	*ft_list_token(char **array)
{
	int	i;
	t_list	*head;
	t_token	*token;

	i = 0;
	token = NULL;
	head = NULL;
	while (array[i] != NULL)
	{
		token = ft_tokenize(array[i], i);
		if (!token)
			return (ft_free_array(array), ft_lstclear(&head, free), NULL);
		ft_lstadd_back(&head, ft_lstnew(token));
		i++;
	}
	ft_free_array(array);
	return (head);
}
