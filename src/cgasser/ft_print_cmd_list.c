

#include "minishell.h"
#include "cgasser.h"
#include "ft_printf.h"

void	ft_print_cmd(t_cmd *cmd);
void	ft_print_redir(t_cmd *cmd);

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
	ft_printf("\n");
}

void	ft_print_cmd(t_cmd *cmd)
{
	t_list	*temp;

	temp = NULL;
	if (cmd->cmd)
		ft_printf("\ncmd: %s", cmd->cmd);
	if (cmd->path)
		ft_printf("\tpath: %s", cmd->path);
	temp = cmd->flags;
	if (cmd->flags)
	{
		ft_printf("\tflags:");
		while (temp != NULL)
		{
			ft_printf(" %s,", (char *)temp->content);
			temp = temp->next;
		}
	}
	temp = cmd->args;
	if (cmd->args)
	{
		ft_printf("\targs:");
		while (temp != NULL)
		{
			ft_printf(" %s,", (char *)temp->content);
			temp = temp->next;
		}
	}
	if (cmd->redirs)
		ft_print_redir(cmd);
	ft_printf("\n");
}

void	ft_print_redir(t_cmd *cmd)
{
	t_list	*temp;

	temp = NULL;
	temp = cmd->redirs;
	ft_printf("\nredirections:");
	while (temp != NULL)
	{
		ft_printf("\ntype: %d, filename: %s", ((t_redir *)temp->content)->type, ((t_redir *)temp->content)->arg);
		temp = temp->next;
	}
}
