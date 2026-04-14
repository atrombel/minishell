/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:52:33 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/03 10:37:18 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_length;

	src_length = ft_strlen(src);
	if (src_length >= size)
	{
		if (size > 0)
		{
			ft_memcpy(dst, src, size);
			dst[size - 1] = '\0';
		}
	}
	else
		ft_memcpy(dst, src, src_length + 1);
	return (src_length);
}
