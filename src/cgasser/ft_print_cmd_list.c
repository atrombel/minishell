

#include "minishell.h"
#include "cgasser.h"
#include "ft_printf.h"

void	ft_print_cmd(t_cmd *cmd);

void	ft_print_cmd_list(t_list *head)
{
	t_list	*temp;

	temp = NULL;
	temp = head;
	while (temp != NULL)
	{
		ft_print_cmd((t_cmd *)temp->content);
		temp = temp->next;
	}
}

void	ft_print_cmd(t_cmd *cmd)
{
	int	i;

	ft_printf("cmd: %s\tflag:", cmd->cmd);
	i = 0;
	if (cmd->flag)
	{
		while (cmd->flag[i] != NULL)
		{
			ft_printf(" %s", cmd->flag[i]);
			i++;
		}
	}
	ft_printf("\targs:");
	i = 0;
	if (cmd->args)
	{
		while (cmd->args[i] != NULL)
		{
			ft_printf(" %s", cmd->args[i]);
			i++;
		}
	}
	ft_printf("\n");
}
