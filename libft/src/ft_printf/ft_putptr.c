/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:40:09 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/30 15:04:52 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexptr(uintptr_t c, int res, int fd);

int	ft_putptr(uintptr_t c, int res, int fd)
{
	if (!c)
		return (write(fd, "(nil)", 5));
	ft_putstr_fd("0x", fd);
	return (ft_puthexptr(c, res, fd) + 2);
}

static int	ft_puthexptr(uintptr_t c, int res, int fd)
{
	char		*hex;

	hex = "0123456789abcdef";
	if (c < 16)
	{
		ft_putchar_fd(hex[c], fd);
		res++;
	}
	else
	{
		res = ft_puthexptr(c / 16, res, fd);
		res = ft_puthexptr(c % 16, res, fd);
	}
	return (res);
}
