

#include "minishell.h"
#include "libft.h"

t_list	*ft_parse(char *str, char **envp)
{
	char	**array;
	t_list	*head;

	array = NULL;
	array = ft_split_quoted(str, ' ');
	free(str);
	head = ft_list_token(array, envp);
	return (head);
}
