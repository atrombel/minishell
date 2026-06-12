/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:20:18 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/12 11:18:05 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

t_redir	*ft_new_redir(void);
int		ft_fill_redir_arg(t_redir *redir, t_token *token, t_data *data);
int		ft_scan_for_quote(char *str);

int	ft_fill_redir(t_cmd *cmd, t_list **temp, t_data *data)
{
	t_redir	*redir;
	t_token	*token;
	t_list	*new;

	token = (t_token *)(*temp)->content;
	redir = NULL;
	new = NULL;
	redir = ft_new_redir();
	if (!redir)
		return (1);
	redir->type = ft_is_redir(token->word);
	*temp = (*temp)->next;
	token = (t_token *)(*temp)->content;
	if (ft_fill_redir_arg(redir, token, data) == 1)
		return (free(redir), 1);
	new = ft_lstnew(redir);
	if (!new)
		return (free(redir->arg), free(redir), 1);
	ft_lstadd_back(&cmd->redirs, new);
	return (0);
}

t_redir	*ft_new_redir(void)
{
	t_redir	*new_redir;

	new_redir = NULL;
	new_redir = ft_calloc(sizeof(t_redir), 1);
	if (!new_redir)
		return (perror("ft_new_redir"), NULL);
	new_redir->hd_tmp_fd = -1;
	new_redir->is_expanded = 1;
	return (new_redir);
}

int	ft_fill_redir_arg(t_redir *redir, t_token *token, t_data *data)
{
	redir->arg = ft_calloc(sizeof(char), ft_strlen(token->word) + 1);
	if (!redir->arg)
		return (perror("ft_fill_redir"), 1);
	ft_strlcpy(redir->arg, token->word, ft_strlen(token->word) + 1);
	if (redir->type == HEREDOC && ft_scan_for_quote(redir->arg))
		redir->is_expanded = 0;
	if (redir->type != HEREDOC)
	{
		redir->arg = ft_expand_var(redir->arg, data);
		if (!redir->arg)
			return (1);
		if (redir->arg[0] == '\0')
			redir->is_ambiguous = 1;
	}
	redir->arg = ft_rm_quotes(redir->arg);
	if (!redir->arg)
		return (1);
	return (0);
}

int	ft_scan_for_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isquote(str[i]))
			return (str[i]);
		i++;
	}
	return (0);
}
