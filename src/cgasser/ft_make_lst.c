
#include "minishell.h"
#include "libft.h"

t_node	*ft_make_lst(int argc, char **argv)
{
	t_node	*head;
	int	i;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		ft_lst_add_front(head, ft_lstnew(argv[i]));
		i++;
	}
	return (head);
}
