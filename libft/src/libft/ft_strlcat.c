/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:25:46 by cgasser           #+#    #+#             */
/*   Updated: 2025/10/06 10:25:50 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length);
	dst_length = ft_strnlen(dst, size);
	if (dst_length != size)
	{
		if (src_length <= size - dst_length - 1)
		{
			ft_memcpy(dst + dst_length, src, src_length);
			dst[dst_length + src_length] = '\0';
		}
		else
		{
			ft_memcpy(dst + dst_length, src, size - dst_length - 1);
			dst[size - 1] = '\0';
		}
	}
	return (dst_length + src_length);
}

size_t	ft_strnlen(const char *str, size_t n)
{
	if (ft_strlen(str) > n)
		return (n);
	return (ft_strlen(str));
}

/*
#include "libft.h"

int	main()
{
	char dest[30]; 
	ft_memset(dest, 'C', 5);
	char * src = (char *)"AAAAAAAAA";

	printf("%zu\n", ft_strlcat(dest, src, -1));
	write(1, dest, 15);
}*/
