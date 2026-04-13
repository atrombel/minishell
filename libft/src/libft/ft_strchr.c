/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:50:36 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/06 10:51:00 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;
	char	cc;

	cc = (char) c;
	i = 0;
	while (s[i] != '\0' && s[i] != cc)
		i++;
	if (s[i] == cc)
	{
		res = (char *)&s[i];
		return (res);
	}
	else
		return (NULL);
}

/*
#include "libft.h"

int	main()
{
	char	*str = "teste";

	printf("%p %p\n", str, ft_strchr(str, 'e'));
}*/
