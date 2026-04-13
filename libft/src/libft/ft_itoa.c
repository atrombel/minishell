/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:25:56 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/09 16:49:12 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countnb(long int n);
char	*ft_putnbr(char *s, long int n, int i);

char	*ft_itoa(int n)
{
	int			i;
	char		*res;
	long int	nb;

	nb = n;
	if (n == 0)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		return (ft_putnbr(res, n, 1));
	}
	i = ft_countnb(nb);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res = ft_putnbr(res, nb, i);
	return (res);
}

int	ft_countnb(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_putnbr(char *s, long int n, int i)
{
	char	*ptr;

	ptr = s + i;
	*ptr = '\0';
	ptr--;
	if (n < 0)
	{
		*s = '-';
		n *= -1;
		i--;
	}
	while (i > 0)
	{
		*(ptr) = n % 10 + '0';
		n /= 10;
		ptr--;
		i--;
	}
	return (s);
}

/*
#include "libft.h"

int	main()
{
	int	n;
	char	*s;

	n = 000;
	s = ft_itoa(n);
	printf("%s\n", s);
	free(s);
	s = NULL;
	return (0);
}*/
