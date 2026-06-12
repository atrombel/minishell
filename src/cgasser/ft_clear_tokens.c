/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:03:51 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/11 14:04:06 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

void	ft_free_token(void *content);

void	ft_clear_tokens(t_list **tokens)
{
	ft_lstclear(tokens, ft_free_token);
}

void	ft_free_token(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	if (token->word)
		free(token->word);
	free(token);
}
