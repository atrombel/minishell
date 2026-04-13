/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:22:12 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/28 11:27:47 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_p(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
}
