/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:28:12 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/30 15:04:50 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	ft_printr(const char *str, ...);
int	ft_sort(const char c, va_list tmp, int fd);
int	ft_putchar_p(int c, int fd);
int	ft_putstr_p(char *s, int fd);
int	ft_putptr(uintptr_t c, int res, int fd);
int	ft_puthex(unsigned int c, int res, int fd);
int	ft_putupphex(unsigned int c, int res, int fd);
int	ft_putnbr_p(int n, int res, int fd);
int	ft_putun(unsigned int n, int res, int fd);
#endif

//merci Matias
