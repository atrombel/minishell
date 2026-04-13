/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:38:44 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/28 15:56:33 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int c, int res, int fd)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c < 16)
	{
		ft_putchar_fd(hex[c], fd);
		res++;
	}
	else
	{
		res = ft_puthex(c / 16, res, fd);
		res = ft_puthex(c % 16, res, fd);
	}
	return (res);
}

/*
int	main()
{
	int	int1 = 43484820;
//	int	int2 = 255;
//	int	int3 = -16;
//	int	int4 = INT_MIN + 1;
//	char	*str = "hello";
//	uintptr_t ptr1 = *str;

	printf("'%d'", ft_puthex(int1, 0));
	ft_putchar_fd('\n', 2);
//	ft_puthex(int2);
//	ft_putchar_fd('\n', 2);
//	ft_puthex(int3);
//	ft_putchar_fd('\n', 2);
//	ft_puthex(int4);
//	ft_putchar_fd('\n', 2);
//	ft_counthex(ptr1);

}*/
