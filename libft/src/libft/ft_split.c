/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:55:55 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/08 15:23:15 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count(char const *s, char c);
char		*ft_find(char const *s, char c);
char const	*ft_reset(char const *s, char c);
char		**ft_free_sp(char **res, int j);

//Allocate memory (using malloc(3)) and returns an array of strings obtained by
//splitting 's' using the character 'c' as a delimiter. The array must end with
//a NULL pointer.

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**res;

	j = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!res)
		return (NULL);
	s = ft_reset(s, c);
	while (*s != '\0')
	{
		res[j] = ft_find(s, c);
		if (!res[j])
			return (ft_free_sp(res, j));
		s += ft_strlen(res[j]);
		s = ft_reset(s, c);
		j++;
	}
	res[j] = NULL;
	return (res);
}

char const	*ft_reset(char const *s, char c)
{
	while (*s != '\0' && *s == c)
		s++;
	return (s);
}

char	*ft_find(char const *s, char c)
{
	char	*end;

	end = ft_strchr(s, c);
	if (!end)
		return (ft_substr(s, 0, ft_strlen(s)));
	return (ft_substr(s, 0, end - s));
}

//count iteration of c in s
//if two or more c in a row, count as one
int	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (s && *s != '\0')
	{
		s = ft_reset(s, c);
		if (s && *s != '\0')
			count++;
		s = ft_strchr(s, c);
	}
	return (count);
}

char	**ft_free_sp(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

/*
#include "libft.h"

int	main()
{
	char	*s = "hello!";
	char	c = 0;
	char	**res;
	int	i;

	res = ft_split(s, c);

	i = 0;
	while (res[i] != NULL)
	{
		printf("'%s' ", res[i]);
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
	res = NULL;
}*/
