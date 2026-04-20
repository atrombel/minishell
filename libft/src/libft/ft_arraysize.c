/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraysize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:40:08 by cgasser           #+#    #+#             */
/*   Updated: 2026/04/20 10:26:02 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arraysize(char **array)
{
	int	size;

	size = 0;
	if (!array)
		return (size);
	while (array[size] != NULL)
		size++;
	return (size);
}
