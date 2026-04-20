
#include "minishell.h"
#include "libft.h"

t_list	*ft_make_lst(int argc, char **argv)
{
	t_list	*head;
	int	i;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		ft_lstadd_front(&head, ft_lstnew(argv[i]));
		i++;
	}
	return (head);
}
