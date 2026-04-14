/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:17:55 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/28 16:38:35 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putun(unsigned int n, int res, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		res++;
	}
	else
	{
		res = ft_putun(n / 10, res, fd);
		res = ft_putun(n % 10, res, fd);
	}
	return (res);
}

/*
int	main()
{
	unsigned int	n = 1034;
	int	tens = 0;

	tens += ft_putun(n);
	printf("%d\n", tens);
}*/
