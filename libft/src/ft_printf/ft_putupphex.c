/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupphex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:55:08 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/28 15:56:30 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putupphex(unsigned int c, int res, int fd)
{
	char		*hex;

	hex = "0123456789ABCDEF";
	if (c < 16)
	{
		ft_putchar_fd(hex[c], fd);
		res++;
	}
	else
	{
		res = ft_putupphex(c / 16, res, fd);
		res = ft_putupphex(c % 16, res, fd);
	}
	return (res);
}
