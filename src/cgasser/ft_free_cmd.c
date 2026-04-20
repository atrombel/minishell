

#include "minishell.h"
#include "cgasser.h"

void	ft_free_cmd(void *cmd)
{
	t_cmd	*temp;

	temp = (t_cmd *)cmd;
	ft_free_array(temp->flag);
	ft_free_array(temp->args);
}
