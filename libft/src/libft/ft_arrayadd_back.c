/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:36:42 by cgasser           #+#    #+#             */
/*   Updated: 2026/04/20 10:26:01 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrayadd_back(char **array, char *str)
{
	int		size;
	char	**res;
	int		i;

	res = NULL;
	i = 0;
	if (!str)
		return (NULL);
	size = 2 + ft_arraysize(array);
	res = malloc(sizeof(char *) * size);
	if (array)
	{
		while (array[i] != NULL)
		{
			res[i] = array[i];
			i++;
		}
		free(array);
	}
	res[i] = str;
	res[i + 1] = NULL;
	return (res);
}
