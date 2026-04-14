/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:29:52 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/30 09:10:51 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//version of printf that write in the stderr

int	ft_printr(const char *str, ...)
{
	int		i;
	va_list	tmp;
	int		res;

	i = 0;
	res = 0;
	va_start(tmp, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (-1);
			res += ft_sort(str[i], tmp, 2);
		}
		else
		{
			ft_putchar_fd(str[i], 2);
			res++;
		}
		i++;
	}
	va_end(tmp);
	return (res);
}
