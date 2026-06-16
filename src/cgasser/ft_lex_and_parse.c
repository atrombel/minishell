/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_and_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:53:42 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/11 14:43:41 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"
#include <stdlib.h>

t_list	*ft_lexer(char **array);
void	ft_token_type(t_token *token);
int		ft_make_and_fill_token(t_list **tokens, char *word);

t_list	*ft_lex_and_parse(char *str, t_data *data)
{
	char	**array;
	t_list	*tokens;

	array = NULL;
	tokens = NULL;
	if (ft_check_quotes(str) != 0)
		return (free(str), NULL);
	array = ft_split_quoted(str);
	free(str);
	if (!array)
		return (NULL);
	if (array[0] == NULL)
		return (ft_free_array(array), NULL);
	tokens = ft_lexer(array);
	if (!tokens)
		return (NULL);
	if (ft_check_syntax(tokens) != 0)
		return (ft_clear_tokens(&tokens), NULL);
	return (ft_parse(tokens, data));
}

t_list	*ft_lexer(char **array)
{
	t_list	*tokens;
	int		i;

	tokens = NULL;
	i = 0;
	while (array[i] != NULL)
	{
		if (ft_make_and_fill_token(&tokens, array[i]) == 1)
			return (ft_free_array(array),
				ft_clear_tokens(&tokens), NULL);
		i++;
	}
	ft_free_array(array);
	return (tokens);
}

void	ft_token_type(t_token *token)
{
	if (ft_is_redir(token->word))
		token->type = REDIR;
	else if (ft_strncmp(token->word, "|", 1) == 0)
		token->type = PIPE;
	else
		token->type = WORD;
}

int	ft_make_and_fill_token(t_list **tokens, char *word)
{
	int		size;
	t_token	*token;
	t_list	*new;

	token = NULL;
	new = NULL;
	size = ft_strlen(word) + 1;
	token = ft_calloc(sizeof(t_token), 1);
	if (!token)
		return (perror("ft_make_and_fill_token"), 1);
	token->word = ft_calloc(sizeof(char), size);
	if (!token->word)
		return (free(token), perror("ft_make_and_fill_token"), 1);
	ft_strlcpy(token->word, word, size);
	ft_token_type(token);
	new = ft_lstnew(token);
	if (!new)
		return (free(token->word), free(token), 1);
	ft_lstadd_back(tokens, new);
	return (0);
}
