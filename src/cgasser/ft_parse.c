/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:47:08 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/12 09:50:05 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"
#include <stdlib.h>

int		ft_make_and_fill_cmd(t_list **cmds, t_list **temp, t_data *data);
t_cmd	*ft_new_cmd(void);
int		ft_init_cmds(t_list **cmds);

t_list	*ft_parse(t_list *tokens, t_data *data)
{
	t_list	*cmds;
	t_list	*temp;
	int		status;

	cmds = NULL;
	temp = tokens;
	status = 0;
	if (ft_init_cmds(&cmds) != 0)
		return (ft_clear_tokens(&tokens), NULL);
	while (temp != NULL)
	{
		status = ft_make_and_fill_cmd(&cmds, &temp, data);
		if (status != 0)
			return (ft_clear_tokens(&tokens), ft_clear_cmds(&cmds), NULL);
		temp = temp->next;
	}
	ft_clear_tokens(&tokens);
	return (cmds);
}

int	ft_make_and_fill_cmd(t_list **cmds, t_list **temp, t_data *data)
{
	t_token	*token;
	t_cmd	*cmd;
	int		status;

	status = 0;
	token = (t_token *)(*temp)->content;
	cmd = (t_cmd *)(ft_lstlast(*cmds)->content);
	if (token->type == PIPE)
		status = ft_init_cmds(cmds);
	else if (token->type == REDIR)
		status = ft_fill_redir(cmd, temp, data);
	else if (token->type == WORD)
		status = ft_fill_cmd(cmd, &token->word, data);
	return (status);
}

t_cmd	*ft_new_cmd(void)
{
	t_cmd	*new_cmd;

	new_cmd = NULL;
	new_cmd = ft_calloc(sizeof(t_cmd), 1);
	if (!new_cmd)
		return (perror("ft_new_cmd"), NULL);
	return (new_cmd);
}

int	ft_init_cmds(t_list **cmds)
{
	t_cmd	*new_cmd;
	t_list	*new_cmd_node;

	new_cmd = NULL;
	new_cmd_node = NULL;
	new_cmd = ft_new_cmd();
	if (!new_cmd)
		return (1);
	new_cmd_node = ft_lstnew(new_cmd);
	if (!new_cmd_node)
		return (free(new_cmd), 1);
	ft_lstadd_back(cmds, new_cmd_node);
	return (0);
}
