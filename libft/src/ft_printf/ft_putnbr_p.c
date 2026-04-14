/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:01:00 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/28 16:17:02 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_p(int n, int res, int fd)
{
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
		res++;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		res++;
	}
	else
	{
		res = ft_putnbr_p(n / 10, res, fd);
		res = ft_putnbr_p(n % 10, res, fd);
	}
	return (res);
}

/*
int	main()
{
	int	n = 35;

	printf("%i\n", ft_putnbr_p(n));
}*/
