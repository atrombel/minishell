/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:20:33 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/30 15:04:56 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putper(va_list tmp, int fd);

//sort and print the appropriate value and return the number of character 
//has been printed
int	ft_sort(const char c, va_list tmp, int fd)
{
	int	res;

	res = 0;
	if (c == '\0')
		return (res);
	if (c == 'c')
		res = ft_putchar_p(va_arg(tmp, int), fd);
	if (c == 's')
		res = ft_putstr_p(va_arg(tmp, char *), fd);
	if (c == 'p')
		res = ft_putptr((unsigned long long)va_arg(tmp, void *), res, fd);
	if (c == 'd' || c == 'i')
		res = ft_putnbr_p(va_arg(tmp, int), res, fd);
	if (c == 'u')
		res = ft_putun(va_arg(tmp, unsigned int), res, fd);
	if (c == 'x')
		res = ft_puthex(va_arg(tmp, int), res, fd);
	if (c == 'X')
		res = ft_putupphex(va_arg(tmp, int), res, fd);
	if (c == '%')
		res = ft_putper(tmp, fd);
	return (res);
}

static int	ft_putper(va_list tmp, int fd)
{
	(void)tmp;
	ft_putchar_fd('%', fd);
	return (1);
}
