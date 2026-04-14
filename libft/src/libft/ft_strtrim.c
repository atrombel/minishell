/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:18:34 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/07 18:32:06 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[j] != '\0')
		j++;
	j--;
	while (is_set(s1[i], set) != 0)
		i++;
	while (is_set(s1[j], set) != 0)
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
int	main()
{
	char	*s1 = "abbabba hello worldies aaabbbaa";
	char	*set = "ba";

	printf("%s\n", ft_strtrim(s1, set));


}*/
