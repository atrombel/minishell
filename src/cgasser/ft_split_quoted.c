/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quoted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:54:37 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/11 13:54:42 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"
#include "ft_printf.h"

int	ft_find_next_word(char *s, int index);
int	ft_count_word_quoted(char *s);
int	ft_len_word_quoted(char *s, int index);
int	ft_len_oper(char *start);

//regular split from the libft, that jump the quoted "" or '' sequences
//allocate memory (using malloc(3)) and returns an array of strings obtained by
//splitting 's' using the character 'c' as a delimiter. The array must end with
//a NULL pointer.

char	**ft_split_quoted(char *s)
{
	int		i;
	int		j;
	int		len_word;
	char	**res;

	j = 0;
	i = 0;
	if (!s || *s == '\0')
		return (NULL);
	res = ft_calloc(sizeof(char *), ft_count_word_quoted(s) + 1);
	if (!res)
		return (perror("ft_split_quoted"), NULL);
	i = ft_find_next_word(s, i);
	while (s[i] != '\0')
	{
		len_word = ft_len_word_quoted(s, i);
		res[j] = ft_calloc(sizeof(char), (len_word + 1));
		if (!res[j])
			return (perror("ft_split_quoted"), ft_free_array(res), NULL);
		ft_strlcpy(res[j], s + i, len_word + 1);
		i += len_word;
		i = ft_find_next_word(s, i);
		j++;
	}
	return (res);
}

int	ft_find_next_word(char *s, int index)
{
	while (ft_isspace(s[index]))
		index++;
	return (index);
}

int	ft_count_word_quoted(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i = ft_find_next_word(s, i);
		if (s[i] != '\0')
			count++;
		i += ft_len_word_quoted(s, i);
	}
	return (count);
}

int	ft_len_word_quoted(char *s, int index)
{
	char	*start;
	int		len;
	int		quote;

	start = s + index;
	len = 0;
	quote = 0;
	if (start[len] == '<' || start[len] == '>' || start[len] == '|')
		return (ft_len_oper(start));
	while (start[len] != '\0' && (quote != 0 || (start[len] != '<'
				&& start[len] != '>' && start[len] != '|'
				&& !ft_isspace(start[len]))))
	{
		if (quote == 0 && ft_isquote(start[len]))
			quote = start[len];
		else if (quote == start[len])
			quote = 0;
		len++;
	}
	return (len);
}

int	ft_len_oper(char *start)
{
	if (ft_strncmp(start, ">>", 2) == 0 || ft_strncmp(start, "<<", 2) == 0)
		return (2);
	if (start[0] == '<' || start[0] == '>' || start[0] == '|')
		return (1);
	return (0);
}
